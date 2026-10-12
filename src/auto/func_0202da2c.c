#include "m2c.h"

M2C_UNK func_0202c1a8(s32, s32);                    /* extern */
s32 func_02033484(s32, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

s32 func_0202da2c(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 temp_r0;
    s32 var_r7;

    temp_r0 = func_0205e80c(0x34, 1, 4);
    var_r7 = temp_r0;
    if (var_r7 != 0) {
        var_r7 = func_02033484(temp_r0, arg0, arg3, arg4, arg6, arg5, arg2, arg1, arg7, arg8);
    }
    func_0202c1a8(arg0 + 0x5E0, var_r7);
    return var_r7;
}
