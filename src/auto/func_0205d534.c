#include "m2c.h"

s32 func_0205d534(void *arg0, void *arg1, s32 arg2) {
    s32 var_r1;

    var_r1 = M2C_FIELD(arg1, s32 *, 8);
    if ((arg2 != 0) && (var_r1 == 0)) {
        var_r1 = M2C_FIELD(arg0, s32 *, 8);
    }
    return var_r1;
}
