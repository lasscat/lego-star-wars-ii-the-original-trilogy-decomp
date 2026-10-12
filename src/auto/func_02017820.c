#include "m2c.h"

s32 func_02017800(M2C_UNK, s32);                    /* extern */

s32 func_02017820(M2C_UNK arg0, s32 arg1) {
    s32 temp_r0;
    s32 var_r4;

    var_r4 = 0;
loop_1:
    temp_r0 = func_02017800(arg0, var_r4);
    if ((temp_r0 != 0) && (temp_r0 != arg1)) {
        return temp_r0;
    }
    var_r4 += 1;
    if (var_r4 >= 0x19) {
        return 0;
    }
    goto loop_1;
}
