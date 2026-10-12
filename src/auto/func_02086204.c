#include "m2c.h"

s32 func_02086204(s32 arg0, s32 arg1) {
    s32 var_r2;

    var_r2 = 1;
    if (!(M2C_FIELD((arg0 + ((arg1 >> 5) * 4)), s32 *, 0x4488) & (1 << (arg1 & 0x1F)))) {
        var_r2 = 0;
    }
    if (var_r2 == 1) {
        return 1;
    }
    return 0;
}
