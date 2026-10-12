#include "m2c.h"

u8 *func_020658e4();          /* extern */

s32 func_02065980(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    s32 var_r4;
    u8 *var_r1;
    u8 var_r0;

    var_r4 = 1;
    var_r1 = func_020658e4();
    var_r0 = *var_r1;
    if (var_r0 != 0) {
        do {
            if (var_r0 == 0xA) {
                var_r1 += 1;
            }
            if (*var_r1 == 0x20) {
                do {
                    var_r1 += 1;
                } while (*var_r1 == 0x20);
            }
            var_r4 += 1;
            var_r1 = func_020658e4(arg0, var_r1, arg2);
            var_r0 = *var_r1;
        } while (var_r0 != 0);
    }
    return var_r4;
}
