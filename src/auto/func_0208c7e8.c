#include "m2c.h"

s32 func_0208c77c(M2C_UNK, u32);                    /* extern */

s32 func_0208c7e8(M2C_UNK arg0) {
    u32 var_r4;

    var_r4 = 0;
loop_1:
    if (func_0208c77c(arg0, var_r4) == 0) {
        return 0;
    }
    var_r4 += 1;
    if (var_r4 >= 0x10U) {
        return 1;
    }
    goto loop_1;
}
