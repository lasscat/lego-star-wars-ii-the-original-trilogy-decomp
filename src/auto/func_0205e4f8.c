#include "m2c.h"

M2C_UNK MIi_CpuClear32(M2C_UNK, s32, s32);          /* extern */
s32 func_0205e540();                                /* extern */

s32 func_0205e4f8(s32 arg0, s32 arg1, u32 arg2) {
    s32 temp_r0;
    u32 temp_r5;

    temp_r0 = func_0205e540();
    if (temp_r0 != 0) {
        temp_r5 = (arg0 + arg2) - 1;
        MIi_CpuClear32(0, temp_r0, temp_r5 - (temp_r5 % arg2));
    }
    return temp_r0;
}
