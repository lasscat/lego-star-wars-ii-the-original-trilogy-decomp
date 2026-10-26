#include "m2c.h"

extern u8 data_020eddb2[];
extern u8 data_020eddac[];
extern u8 data_020ef57c[];
extern u8 data_02104d90[];

s32 func_02086534(void *, s32);
s32 func_02086204(void *, s32);
s32 func_02068e34(s32, s32, s32, u16, void *, void *, s32);

typedef struct {
    u8 pad0[8];
    u32 flags;
    u8 pad_c[8];
    struct {
        u32 low : 12;
        u32 nib : 4;
        u32 high : 16;
    } f14;
    u8 pad_18[0x34];
    s32 f4c;
    s32 f50;
    u8 pad_54[0x667];
    u8 f6bb;
} Item;

typedef struct {
    u8 pad0[8];
    Item *items[8];
} Group;

typedef struct {
    u8 pad0[0x4c];
    Item *slots[4];
} Globals;

typedef struct Screen {
    u8 pad0[0xC];
    Group *group;
    u8 pad10[8];
    void *f18;
    u8 pad1C[4];
    s32 f20;
    u8 pad24[0x11];
    u8 f35;
    u8 f36;
} Screen;

extern Globals data_0210930c;

enum {
    ENTRY_NONE      = 100,  /* ids >= 100 mean "no entry" for a slot */
    SLOT_STATE_MASK = 0x803,
    SLOT_STATE_SET  = 0x1,
    NIB_DEFAULT     = 0xe,
    NIB_SPECIAL     = 0xf,
    ENTRY_SIZE      = 24,
    ENTRY_DATA_OFS  = 8,
    ENTRY_COUNT     = 8,
    PLAYER_SLOTS    = 4,
};

/* Called by func_02068d74 (screen setup).  For each of the 8 items of the screen's group, picks an entry id
 * (from the per-mode table data_020eddb2, or from the player objects in data_0210930c when f35 is set),
 * updates the item's 4-bit field at bit 12 of f14 (non-f35 mode), calls func_02068e34 with the entry data
 * (accumulating its return value and a running u16 counter) and sets or clears bit 0 of the item flags
 * depending on whether the item had a valid entry. */

void func_02068fbc(Screen *self) {
    s32 acc = 1;
    u32 i;
    u32 flag;
    u32 v;
    u32 nib;
    u32 j = 4;

    for (i = 0; i < ENTRY_COUNT; i++) {
        u8 *tbl = &data_020eddb2[self->f20 * 8];
        flag    = 0;
        v       = tbl[i];
        if (self->f35 != 0) {
            Item *o;
            if (i >= PLAYER_SLOTS) {
                return;
            }
            o = data_0210930c.slots[i];
            if (o != NULL && (o->flags & SLOT_STATE_MASK) == SLOT_STATE_SET) {
                v = o->f6bb;
            } else {
                v = ENTRY_NONE;
            }
        } else {
            nib = NIB_DEFAULT;
            if (v < ENTRY_NONE) {
                if (func_02086534(data_02104d90, v) != 0) {
                    nib = NIB_SPECIAL;
                }
            }
            self->group->items[i]->f14.nib = nib;
        }
        if (v < ENTRY_NONE) {
            if (func_02086534(data_02104d90, v) != 0 || func_02086204(data_02104d90, 10) == 0) {
                Item *it = self->group->items[i];
                acc += func_02068e34(acc, it->f4c >> 12, it->f50 >> 12, (u16) j++, self->f18,
                                     data_020ef57c + v * ENTRY_SIZE + ENTRY_DATA_OFS, 2);
            } else {
                acc += func_02068e34(acc, self->group->items[i]->f4c >> 12, self->group->items[i]->f50 >> 12, (u16) j++,
                                     self->f18, data_020eddac, 2);
            }
            flag = 1;
        }
        {
            Item *it = self->group->items[i];
            u32 f    = it->flags;
            if (flag) {
                f |= 1;
            } else {
                f &= ~1u;
            }
            it->flags = f;
        }
    }
}
