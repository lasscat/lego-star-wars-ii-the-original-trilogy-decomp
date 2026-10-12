#include "m2c.h"

s32 func_02073034();                                /* extern */
s32 func_0209bc04(M2C_UNK, u8);                     /* extern */

u8 func_0209bad8(M2C_UNK arg0) {
    s32 temp_r4;
    u8 var_r5;
    u8 var_r6;

    var_r5 = 0;
    var_r6 = 1;
    if (func_02073034() > 1) {
        do {
            temp_r4 = func_0209bc04(arg0, var_r6);
            if (temp_r4 > func_0209bc04(arg0, var_r5)) {
                var_r5 = var_r6;
            }
            var_r6 += 1;
        } while ((s32) var_r6 < func_02073034());
    }
    return var_r5;
}
