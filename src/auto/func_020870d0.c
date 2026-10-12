#include "m2c.h"

s32 func_02062a7c(s32, M2C_UNK);                    /* extern */
s32 func_02086534(M2C_UNK, s32);                    /* extern */

s32 func_020870d0(M2C_UNK arg0) {
    s32 var_r6;
    u32 var_r7;

    var_r7 = 0;
loop_1:
    if (var_r7 > 0x1EU) {
        var_r6 = 0x38;
    } else {
        var_r6 = func_02062a7c(0, 0x47);
        var_r7 = (u32) (u8) (var_r7 + 1);
        if (func_02086534(arg0, var_r6) == 0) {
            goto loop_1;
        }
    }
    return var_r6;
}
