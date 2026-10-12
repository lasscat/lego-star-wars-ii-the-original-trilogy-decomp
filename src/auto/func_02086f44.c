#include "m2c.h"

s32 func_02086534(M2C_UNK, u32);                    /* extern */

u32 func_02086f44(M2C_UNK arg0, u32 arg1) {
    u32 var_r5;

    var_r5 = arg1;
    do {
        var_r5 += 1;
        if (var_r5 >= 0x47U) {
            var_r5 = 0;
        }
    } while (func_02086534(arg0, var_r5) == 0);
    return var_r5;
}
