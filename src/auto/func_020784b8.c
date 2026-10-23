/* Reconstructed from USA ARM9 at 0x020784b8 (760 bytes).
 *
 * data_021044a4 is the shared timer/state block (bit field flags in the first
 * byte, signed 16-bit times at 0x2a and 0x2c).  data_020ee4e8 is a read-only
 * table of nineteen 8-byte entries of four 16-bit values; an entry matches
 * when the first time is in [f0, f0+f2) and the second time is in [f1, f1+f3).
 * The matching entry selects the reaction, the entry index also being the
 * index of the reaction.  data_021027f8 is the controller/pad state block
 * whose buttons are polled with func_0205d0d0.
 */
#include "m2c.h"

struct S_020784b8_Data {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad[0x29];
    s16 f2a;
    s16 f2c;
};

struct S_020784b8_Entry {
    u16 f0;
    u16 f1;
    u16 f2;
    u16 f3;
};

typedef struct {
    u8 pad[0xd2];
    s8 f_d2;
    u8 pad_d3[0xd9 - 0xd3];
    s8 f_d9;
    u8 pad_da[0x12c - 0xda];
    void *f_12c;
} S_020784b8_Self;

extern struct S_020784b8_Data data_021044a4;
extern struct S_020784b8_Entry data_020ee4e8[19];
extern u8 data_021027f8[];

void func_0207a230(M2C_UNK);
void func_0207a3e0(M2C_UNK);
void func_02077a88(M2C_UNK);
void func_02077b38(M2C_UNK);
void func_020b8f70(M2C_UNK, s32);
s32 func_0205d0d0(void *, s32, s32);
void func_0201b318(void *, u8);
void func_020787b0(M2C_UNK);

s32 func_020784b8(S_020784b8_Self *self) {
    s32 changed;
    u32 idx;
    s32 i;
    u16 y;

    if (self->f_d9 > 0) {
        self->f_d9 = self->f_d9 - 1;
        if (self->f_d9 == 0) {
            func_0201b318(self->f_12c, 0);
        }
    }
    changed = 0;
    if (data_021044a4.b4) {
        idx = 19;
        y   = (u16) (s16) (s32) data_021044a4.f2c;
        for (i = 0; i < 19; i++) {
            u16 g3 = data_020ee4e8[i].f3;
            u16 g2 = data_020ee4e8[i].f2;
            u16 g1 = data_020ee4e8[i].f1;
            u16 g0 = data_020ee4e8[i].f0;
            if ((u32) (u16) (s16) (s32) data_021044a4.f2a >= (u32) g0 &&
                (s32) (u16) (s16) (s32) data_021044a4.f2a < (s32) ((u32) g0 + (u32) g2) && (u32) y >= (u32) g1 &&
                (s32) y < (s32) ((u32) g1 + (u32) g3)) {
                if (i >= 12 || self->f_d2 == i / 2) {
                    idx = i;
                    i   = 19; /* leave the search loop */
                }
            }
        }
        if (idx == 19) {
            return 0;
        }
        if (idx <= 11) {
            if (self->f_d2 == idx / 2) {
                if ((idx & 1) == 0) {
                    changed = 1;
                    func_0207a3e0(self);
                    func_02077a88(self);
                } else {
                    changed = 1;
                    func_0207a230(self);
                    func_02077a88(self);
                }
            }
            func_020b8f70(0xb6, 0);
        } else if (idx == 18) {
            self->f_d9 = 5;
            func_0201b318(self->f_12c, 1);
            func_020787b0(self);
            changed = 1;
        } else if (idx < 19) {
            self->f_d2 = idx - 12;
            func_02077b38(self);
            changed = 1;
            func_020b8f70(0xb6, 0);
        }
        if (changed) {
            return 1;
        }
    }
    if (func_0205d0d0(data_021027f8, 0x10, 4)) {
        self->f_d2 = self->f_d2 + 1;
        if (self->f_d2 >= 6) {
            self->f_d2 = 5;
        }
        func_02077b38(self);
        changed = 1;
        func_020b8f70(0xb6, 0);
    }
    if (func_0205d0d0(data_021027f8, 0x20, 4)) {
        self->f_d2 = self->f_d2 - 1;
        if (self->f_d2 <= 0) {
            self->f_d2 = 0;
        }
        func_02077b38(self);
        changed = 1;
        func_020b8f70(0xb6, 0);
    }
    if (func_0205d0d0(data_021027f8, 0x40, 4)) {
        func_0207a3e0(self);
        func_02077a88(self);
        changed = 1;
        func_020b8f70(0xb4, 0);
    }
    if (func_0205d0d0(data_021027f8, 0x80, 4)) {
        func_0207a230(self);
        func_02077a88(self);
        changed = 1;
        func_020b8f70(0xb4, 0);
    }
    if (func_0205d0d0(data_021027f8, 0x01, 4)) {
        self->f_d9 = 5;
        func_0201b318(self->f_12c, 1);
        func_020787b0(self);
        changed = 1;
    }
    return changed ? 1 : 0;
}
