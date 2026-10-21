#include "m2c.h"

s32 func_020ab704(s32 *a0, u32 a1) {
    s32 *t  = M2C_FIELD(a0, s32 *, 0xc);
    u16 off = M2C_FIELD(t, u16 *, 0x34);
    s32 v   = M2C_FIELD(t, s32 *, 0x2c);
    u8 *row = (u8 *) t + off;
    u8 flag = M2C_FIELD(row, u8 *, 1);
    s32 res = ((v & 0xffff0000) >> 16) * 8;
    u16 idx;
    u16 stride;
    u16 e0;
    u16 e1;
    s32 e0x;
    u8 *base;

    if (flag == 1) {
        return res;
    }
    idx    = M2C_FIELD(row, u16 *, 6);
    stride = M2C_FIELD(row, u16 *, idx);
    base   = row + idx;
    e0     = M2C_FIELD(base + stride * a1, u16 *, 4);
    e0x    = e0 * 8;
    if (a1 + 1 >= (u32) flag) {
        res -= e0x;
        return res;
    }
    e1 = M2C_FIELD(base + stride * (a1 + 1), u16 *, 4);
    return e1 * 8 - e0x;
}
