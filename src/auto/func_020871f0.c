#include "m2c.h"

s32 func_02086740(M2C_UNK, u8);                     /* extern */
s32 func_020867ec(M2C_UNK, u8);                     /* extern */
M2C_UNK func_02086810(M2C_UNK, u8, s32);            /* extern */

void func_020871f0(M2C_UNK arg0) {
    u8 var_r5;

    var_r5 = 0;
    do {
        if ((func_02086740(arg0, var_r5) == 0) && (func_020867ec(arg0, var_r5) != 0)) {
            func_02086810(arg0, var_r5, 0);
        }
        var_r5 += 1;
    } while ((u32) var_r5 < 0x1DU);
}
