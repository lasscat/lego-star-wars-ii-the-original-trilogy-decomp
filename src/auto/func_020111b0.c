#include "m2c.h"

s32 func_020111b0(void *arg0, s32 arg1) {
    s32 var_r0;

    var_r0 = M2C_FIELD(arg0, s32 *, 0x1B8) & arg1;
    if (var_r0 & 0x40) {
        var_r0 = 0;
    }
    return var_r0;
}
