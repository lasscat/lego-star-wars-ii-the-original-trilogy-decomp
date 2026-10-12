#include "m2c.h"

s32 func_020b0c60(s32 arg0, s32 arg1) {
    s32 var_r2;

    var_r2 = 1;
    if (!(arg0 & (1 << arg1))) {
        var_r2 = 0;
    }
    return var_r2;
}
