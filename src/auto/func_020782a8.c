/* Reconstructed from USA ARM9 at 0x020782a8 (528 bytes).
 *
 * data_021044a4 is the shared timer/state block (bit field flags in the first
 * byte, signed 16-bit times at 0x2a and 0x2c).  data_020ee2da is a read-only
 * table of three 8-byte entries of four 16-bit values; an entry matches when
 * the first time is in [f0, f0+f2) and the second time is in [f1, f1+f3).
 * The matching entry selects one of three reactions, otherwise the reaction
 * is chosen from the flag bits of data_021027f8.
 */
#include "m2c.h"

struct S_020782a8_Data {
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

struct S_020782a8_Entry {
    u16 f0;
    u16 f1;
    u16 f2;
    u16 f3;
};

typedef struct {
    u8 pad[0xd2];
    s8 f_d2;
    u8 f_d3;
    u8 f_d4;
} S_020782a8_Self;

extern struct S_020782a8_Data data_021044a4;
extern struct S_020782a8_Entry data_020ee2da[3];
extern M2C_UNK data_021027f8;

void func_0207a230(M2C_UNK);
void func_0207a3e0(M2C_UNK);
void func_020771bc(M2C_UNK, s8);
void func_020b8f70(M2C_UNK, s32);
s32 func_0205d0d0(void *, s32, s32);

s32 func_020782a8(S_020782a8_Self *self) {
    s32 idx;
    s32 i;
    s32 ok;
    u16 y;

    if (data_021044a4.b4) {
        idx = 3;
        ok  = 0;
        y   = (u16) (s16) (s32) data_021044a4.f2c;
        for (i = 0; i < 3; i++) {
            u16 g3 = data_020ee2da[i].f3;
            u16 g2 = data_020ee2da[i].f2;
            u16 g1 = data_020ee2da[i].f1;
            u16 g0 = data_020ee2da[i].f0;
            if ((u32) (u16) (s16) (s32) data_021044a4.f2a >= (u32) g0 &&
                (s32) (u16) (s16) (s32) data_021044a4.f2a < (s32) ((u32) g0 + (u32) g2) && (u32) y >= (u32) g1 &&
                (s32) y < (s32) ((u32) g1 + (u32) g3)) {
                idx = i;
                i   = 3; /* leave the search loop */
            }
        }
        if (idx == 3) {
            return 0;
        }
        /* the original listed the cases in this order */
        switch (idx) {
            case 1:
                self->f_d3 = 0xd;
                self->f_d4 = 0;
                func_0207a230(self);
                ok = 1;
                func_020b8f70(0xb6, 0);
                break;
            case 0:
                self->f_d3 = 0xd;
                self->f_d4 = 1;
                func_0207a3e0(self);
                ok = 1;
                func_020b8f70(0xb6, 0);
                break;
            case 2:
                func_020771bc(self, self->f_d2);
                ok = 1;
                func_020b8f70(0xb4, 0);
                break;
        }
        if (ok) {
            return 1;
        }
    }
    if (func_0205d0d0(&data_021027f8, 0x10, 4)) {
        self->f_d3 = 0xd;
        self->f_d4 = 0;
        func_0207a230(self);
        func_020b8f70(0xb6, 0);
        return 1;
    }
    if (func_0205d0d0(&data_021027f8, 0x20, 4)) {
        self->f_d3 = 0xd;
        self->f_d4 = 1;
        func_0207a3e0(self);
        func_020b8f70(0xb6, 0);
        return 1;
    }
    if (!func_0205d0d0(&data_021027f8, 0x01, 4)) {
        return 0;
    }
    func_020771bc(self, self->f_d2);
    func_020b8f70(0xb4, 0);
    return 1;
}
