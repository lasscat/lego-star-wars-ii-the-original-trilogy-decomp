#include "m2c.h"

M2C_UNK func_02057cf8(void *, s32, u8, u8);         /* extern */
s32 func_02067080(void *, s32, u32);                /* extern */

void func_02055f48(void *arg0, void *arg1) {
    s32 temp_r0;
    s32 var_r6;
    u32 var_r7;
    u8 temp_r2;
    u8 var_r8;
    s32 base;

    temp_r2 = M2C_FIELD(arg1, u8 *, 0);
    base    = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r2 == 0) {
        var_r8 = 0;
    } else {
        var_r8 = M2C_FIELD(M2C_FIELD(base, s32 *, 0x2C) + ((temp_r2 - 1) * 8), u8 *, 5);
    }
    var_r7 = 1;
    if ((u32) var_r8 < 1U) {
        return;
    }
    var_r6 = temp_r2 - 1;
    do {
        temp_r0 = func_02067080(arg0, var_r6, var_r7);
        if (temp_r0 != 0) {
            func_02057cf8(arg0, temp_r0, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2));
        }
        var_r7 += 1;
    } while (var_r7 <= (u32) var_r8);
}
