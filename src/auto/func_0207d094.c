#include "m2c.h"

extern u8 data_020effa0[];
extern u8 data_020ef57c[];
extern u32 data_02104d5c[];

extern s32 func_02068e34(s32, s16, s16, u16, void *, void *, s32);

typedef struct {
    u8 pad_0[0xa0];
    s32 f_a0;
    u32 *f_a4;
} Obj;

void func_0207d094(Obj *a0) {
    u32 i;
    u32 j;
    u32 flag;
    u8 *rec;
    u32 *e;

    rec = data_020effa0;
    j   = 5;
    for (i = 0; i < 8; i++) {
        u32 v = data_02104d5c[i + 2];
        flag  = 0;
        if (v < 100) {
            {
                u16 jv = (u16) j;
                j++;
                a0->f_a0 += func_02068e34(a0->f_a0, *(s16 *) (rec + 6), *(s16 *) (rec + 8), jv, (u8 *) a0 + 0x30,
                                          data_020ef57c + v * 24 + 8, 2);
            }
            e    = a0->f_a4[i];
            e[5] = (e[5] & ~0xf000u) | 0xf000u;
            flag = 1;
        }
        rec += 12;
        e = a0->f_a4[i];
        if (flag) {
            e[2] |= 1;
        } else {
            e[2] &= ~1u;
        }
    }
}
