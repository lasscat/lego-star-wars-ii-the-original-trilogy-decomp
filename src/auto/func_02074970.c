#include "m2c.h"

s32 func_02062a7c(M2C_UNK, M2C_UNK);                /* extern */
s32 func_02062b3c(M2C_UNK);                         /* extern */

void func_02074970(s32 arg0, void *arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 var_r4;

    var_r4 = func_02062a7c(arg2, arg3);
    if (func_02062b3c(0x32) != 0) {
        var_r4 *= -1;
    }
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) + (var_r4 << 0xC));
}
