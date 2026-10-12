#include "m2c.h"

s32 func_020508b4(s32);                             /* extern */

s32 func_02017800(s32 arg0, s32 arg1) {
    s32 var_r0;

    var_r0 = func_020508b4(arg0 + 0x1DE + (arg1 * 2));
    if (var_r0 == 0) {
        var_r0 = 0;
    }
    return var_r0;
}
