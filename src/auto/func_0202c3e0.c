#include "m2c.h"

s32 func_0202c710(void *, s32, s32, M2C_UNK);       /* extern */

s32 func_0202c3e0(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r0;
    s32 var_r1;
    s32 var_r3;

    var_r3 = arg1;
    var_r1 = M2C_FIELD(arg0, s32 *, 4);
    if (var_r3 != 0) {
        var_r3 -= 4;
    }
    if (var_r1 != 0) {
        var_r1 -= 4;
    }
    var_r0 = func_0202c710(arg0, var_r1, var_r3, 0);
    if ((arg2 != 0) && (var_r0 == 0)) {
        var_r0 = M2C_FIELD(arg0, s32 *, 4);
        if (var_r0 != 0) {
            var_r0 -= 4;
        }
    }
    if (var_r0 != 0) {
        var_r0 += 4;
    }
    return var_r0;
}
