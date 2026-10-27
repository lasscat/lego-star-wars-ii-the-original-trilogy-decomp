#include "m2c.h"

typedef struct {
    u8 pad0[8];
    u32 flags;
    u8 pad1[8];
    u32 attr; /* bits 12-15 take a per-slot nibble from data_020ee580 */
    u8 idx;
    u8 idx2;
} Widget;

typedef struct {
    u8 pad0[0xd0];
    u8 mode;
    u8 f_d1;
    u8 f_d2;
    u8 pad2[9];
    Widget *w_dc;
    Widget *w_e0;
    Widget *w_e4;
    Widget *w_e8;
    u8 pad3[8];
    Widget *items[8];
    u8 pad4[0x18];
    Widget *w_12c;
} Obj;

extern u16 data_020ee294[];
extern const u16 data_020ee2a0[];
extern u8 data_020ee2c8[];
/* 12-byte slot layout rows: x/y are passed to func_0201c1e4 (position setter). */
typedef struct {
    u8 pad0[6];
    s16 x;
    s16 y;
    u8 pad1;
    u8 nib;
} SlotRow;
extern SlotRow data_020ee580[];
extern u8 data_020ee598[];
extern u8 data_020ee5a4[];
typedef struct {
    u8 b[6];
} Entry6;
extern Entry6 *data_020fed4c[];

void func_0205365c(void *, s32);
void func_0206574c(void *, s32, s32);
void func_02065be8(void *, s32, s32, s32, s32, s32);
s32 func_02066708(s32);
void func_02077d04(void *, s32);
void func_02077e60(void *, s32);
void func_0207a744(void *);
void func_0201c1e4(void *, s32, s32);
void clearDataAndInstructionCache(void *, void *);
void func_02077414(void *);

enum {
    LABEL_NONE    = 0x535, /* func_02077e60 skips the label for ids >= 0x535 */
    FLAG_BIT0     = 0x1,
    FLAG_BIT3     = 0x8,
    MODE_1        = 1,
    MODE_3        = 3,
    MODE_NO_SLOTS = 5,
    ROW_MODE_1    = 6,
    ROW_OTHER     = 13,
    SLOT_X0       = 0x1e,
    SLOT_DX       = 0x23,
    SLOT_Y        = 0x67,
};

/*
 * Rebuilds the widgets of this object for its mode byte (+0xd0), then
 * refreshes it through func_02077414:
 *  1. picks a per-mode text id (data_020ee294[0x11..0x16]) for func_02065be8;
 *  2. clears the label (LABEL_NONE) and resets the bytes at +0xd1/+0xd2;
 *  3. unless the mode is 5, sets bit 0 on the fixed widgets and places the
 *     two at +0xe4/+0xe8 with a mode-3 or default layout;
 *  4. for each of the mode's slots (count table data_020ee2a0[3 + mode]),
 *     sets the slot widget's attr nibble, data pointer, flags, index bytes
 *     and position (fixed row for mode 3, data_020ee580 rows otherwise).
 */

void func_0207759c(Obj *self) {
    u16 mode_text_ids[6];

    mode_text_ids[0] = data_020ee294[0x11];
    mode_text_ids[1] = data_020ee294[0x12];
    mode_text_ids[2] = data_020ee294[0x13];
    mode_text_ids[3] = data_020ee294[0x14];
    mode_text_ids[4] = data_020ee294[0x15];
    mode_text_ids[5] = data_020ee294[0x16];
    func_0205365c((u8 *) self + 0x28, 0);
    func_0206574c((u8 *) self + 0xa0, 9, -1);
    func_02065be8((u8 *) self + 0xa0, 1, 0x80, 0x3d, func_02066708(mode_text_ids[self->mode]), 1);
    func_02077d04(self, 0);
    func_02077e60(self, LABEL_NONE);
    self->f_d1 = 0;
    self->f_d2 = 3;
    if (self->mode != MODE_NO_SLOTS) {
        func_0207a744(self);
        self->w_e4->flags |= FLAG_BIT0;
        self->w_e8->flags |= FLAG_BIT0;
        self->w_dc->flags |= FLAG_BIT0;
        if (self->mode == MODE_3) {
            self->f_d2 = 0;
            self->w_12c->flags |= FLAG_BIT0;
            func_0201c1e4(self->w_e4, 0x28, 0x59);
            func_0201c1e4(self->w_e8, 0x28, 0x89);
            clearDataAndInstructionCache(self->w_e4, &data_020ee2a0[0x11]);
            clearDataAndInstructionCache(self->w_e8, data_020ee2c8);
        } else {
            self->w_12c->flags &= ~FLAG_BIT0;
            self->w_e0->flags |= FLAG_BIT0;
            func_0201c1e4(self->w_e4, 0x17, 0x6f);
            func_0201c1e4(self->w_e8, 0xe8, 0x6f);
            clearDataAndInstructionCache(self->w_e4, data_020ee598);
            clearDataAndInstructionCache(self->w_e8, data_020ee5a4);
        }
        {
            const u16 *slot_count = &data_020ee2a0[3];
            u32 i;
            if (slot_count[self->mode] != 0) {
                Entry6 *slot_data = data_020fed4c[self->mode];
                for (i = 0; i < slot_count[self->mode]; i++) {
                    Widget *w = self->items[i];
                    Widget *w2;
                    w->attr = (w->attr & ~0xf000) | ((data_020ee580[i + ROW_MODE_1].nib & 0xf) << 12);
                    clearDataAndInstructionCache(self->items[i], &slot_data[i]);
                    self->items[i]->flags |= FLAG_BIT0;
                    self->items[i]->flags &= ~FLAG_BIT3;
                    w2       = self->items[i];
                    w2->idx2 = w2->idx = 0;
                    if (self->mode == MODE_3) {
                        func_0201c1e4(self->items[i], SLOT_X0 + i * SLOT_DX, SLOT_Y);
                    } else if (self->mode == MODE_1) {
                        func_0201c1e4(self->items[i], data_020ee580[i + ROW_MODE_1].x, data_020ee580[i + ROW_MODE_1].y);
                    } else {
                        func_0201c1e4(self->items[i], data_020ee580[i + ROW_OTHER].x, data_020ee580[i + ROW_OTHER].y);
                    }
                }
            }
        }
    }
    func_02077414(self);
}
