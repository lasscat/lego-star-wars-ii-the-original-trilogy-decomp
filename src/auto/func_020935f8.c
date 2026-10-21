#include "m2c.h"

s32 func_02067b18(s8 *);                            /* extern */
s16 *func_02067b0c(s8 *, s32);                      /* extern */

s32 func_020935f8(void *arg0, s32 arg1, void *arg2) {
    u32 bestd;
    s32 best;
    s32 count;
    s32 i;
    s8 *arr;
    s8 *desc;
    s16 *e;
    s32 t0;
    s32 t1;
    s32 t2;
    u32 dist;

    bestd = 0xFFFFFFFF;
    best  = -1;
    desc  = M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x38C), void **, 0x4), void **, 0x34);
    arr   = desc + arg1 * 8;
    count = func_02067b18(arr);
    i     = 0;
    while (i < count) {
        e    = func_02067b0c(arr, i);
        t0   = M2C_FIELD(e, s16 *, 0) - (M2C_FIELD(arg2, s32 *, 0) >> 12);
        t1   = M2C_FIELD(e, s16 *, 2) - (M2C_FIELD(arg2, s32 *, 4) >> 12);
        t2   = M2C_FIELD(e, s16 *, 4) - (M2C_FIELD(arg2, s32 *, 8) >> 12);
        dist = (u32) (t0 * t0) + (u32) (t1 * t1) + (u32) (t2 * t2);
        if (dist < bestd) {
            best  = i;
            bestd = dist;
        }
        i++;
    }
    return best;
}
