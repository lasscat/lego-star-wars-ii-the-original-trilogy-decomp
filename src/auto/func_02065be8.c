#include "m2c.h"

s32 func_02065840(M2C_UNK, s32);                    /* extern */
s32 func_020658c8(M2C_UNK, s32);                    /* extern */
M2C_UNK func_02065c90(M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */

void func_02065be8(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_r6;
    s32 var_r7;
    u32 temp_r0;
    u32 temp_r0_2;

    var_r7 = arg2;
    var_r6 = arg3;
    if (arg5 == 1) {
        temp_r0 = func_02065840(arg0, arg4) + 1;
        var_r7 -= (s32) (temp_r0 + (temp_r0 >> 0x1F)) >> 1;
    } else if (arg5 == 2) {
        var_r7 -= func_02065840(arg0, arg4);
    }
    if (arg5 == 4) {
        temp_r0_2 = func_020658c8(arg0, arg4) + 1;
        var_r6 -= (s32) (temp_r0_2 + (temp_r0_2 >> 0x1F)) >> 1;
    } else if (arg5 == 8) {
        var_r6 -= func_020658c8(arg0, arg4);
    }
    func_02065c90(arg0, arg1, var_r7, var_r6, arg4);
}
