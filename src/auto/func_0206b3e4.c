#include "m2c.h"

typedef struct {
    u8 pad0[0xC];
    void *gfx;
    s32 unk10;
    u8 pad14[4];
    s32 selected;
    s32 base;
    u8 pad20[4];
    u32 count;
    u8 entries[0x25];
    u8 done;
} Menu;

extern void func_0206574c(void *, s32, s32);
extern s32 func_02053b14(s32);
extern void MIi_CpuClearFast(s32, s32, s32);
extern s32 func_02065be8(void *, s32, s32, s32, s32, s32);
extern void func_020661b4(void *, s32);
extern void func_020660e4(void *, s32, s32, s32, u16);
extern s32 func_02066708(s32);
extern void func_02064b3c(void *, s16 *, void *, s32, s32);

extern u16 data_020edea4[];
extern u8 data_02104364[];

/* Redraws the row list of a menu object. When `first` is nonzero the
 * graphics state is set up and the base handle (field 0x1C) allocated.
 * Row `selected` is passed mode 3, the others mode 0. The first
 * two rows also clear three 0x20-wide strips; each row is placed 0x1E units
 * below the previous one, starting at 0x28. Row entries (12 bytes each) are
 * filled once, guarded by the `done` flag at 0x4D. */
void func_0206b3e4(Menu *self, s32 first) {
    u16 ids[3];
    s16 rect[2];
    s32 h;
    u32 i;
    u32 y;
    u8 *ent;
    s32 id;
    s32 v;
    s32 row;

    ids[0] = data_020edea4[4];
    ids[1] = data_020edea4[5];
    ids[2] = data_020edea4[6];
    if (first != 0) {
        func_0206574c(self->gfx, 6, -2);
        self->base = func_02065be8(self->gfx, 1, 0x80, 8, func_02066708(0x4D), 1);
    }
    MIi_CpuClearFast(0, func_02053b14(self->unk10) + 0x100, 0x3C0);
    h = self->base;
    i = 0;
    if (i < self->count) {
        y   = 0x28;
        ent = self->entries;
        do {
            if (i == self->selected) {
                func_0206574c(self->gfx, 3, -2);
            } else {
                func_0206574c(self->gfx, 0, -2);
            }
            if (i <= 1) {
                v = data_02104364[10];
                if (i == 1) {
                    v = data_02104364[9];
                }
                func_020661b4(self->gfx, v);
                row = y >> 3;
                func_020660e4(self->gfx, 0, row, 0x20, 0);
                func_020660e4(self->gfx, 0, row + 1, 0x20, 0);
                func_020660e4(self->gfx, 0, row + 2, 0x20, 0);
            }
            id = ids[i];
            h  = func_02065be8(self->gfx, h, 0x80, y, func_02066708(id), 1);
            if (self->done == 0) {
                rect[0] = 0x80;
                rect[1] = y;
                func_02064b3c(ent, rect, self->gfx, id, 1);
            }
            y += 0x1E;
            ent += 12;
            i++;
        } while (i < self->count);
    }
    self->done = 1;
}
