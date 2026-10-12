#include "m2c.h"

M2C_UNK func_0202c1a8(s32, s32);                    /* extern */
s32 func_0203b698(s32, s32, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

s32 func_0202daac(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_r0;
    s32 var_r7;

    temp_r0 = func_0205e80c(0x60, 1, 4);
    var_r7 = temp_r0;
    if (var_r7 != 0) {
        var_r7 = func_0203b698(temp_r0, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    }
    func_0202c1a8(arg0 + 0x5E0, var_r7);
    return var_r7;
}
