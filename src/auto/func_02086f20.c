#include "m2c.h"

s32 func_02086f20(s32 arg0, s32 arg1) {
    s32 var_r0;

    var_r0 = 1;
    if (!(M2C_FIELD((arg0 + ((arg1 >> 5) * 4)), s32 *, 0x4520) & (1 << (arg1 & 0x1F)))) {
        var_r0 = 0;
    }
    return var_r0;
}
