#include "m2c.h"

extern u8 data_020ee030[];
extern u8 data_020ee048[];
extern u8 data_021027f8[];
extern u32 data_02109358[];

extern u32 func_02062b10(s32);
extern s32 func_02062ab4(s32, s32);
extern void func_020b9584(s32, void *);

void func_0206818c(u8 *a0) {
    u32 *p;
    u32 v[3];
    u16 d;
    u16 e;

    d    = *(u16 *) (data_020ee030 + a0[0] * 26 + func_02062b10(9) * 2);
    p    = data_02109358[data_021027f8[0x2a]];
    v[0] = p[0x2c];
    v[1] = p[0x2d];
    v[2] = p[0x2e];
    e    = *(u16 *) (data_020ee048 + a0[0] * 26);

    v[0] += func_02062ab4(-e, e) << 12;
    v[1] += func_02062ab4(-e, e) << 12;
    v[2] += func_02062ab4(-e, e) << 12;
    func_020b9584(d, v);
}
