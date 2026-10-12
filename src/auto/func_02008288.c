#include "m2c.h"

void func_02008288(s32 arg0, s32 arg1, s32 arg2) {
    s8 var_r2;

    if (arg2 != 0) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    M2C_FIELD(M2C_FIELD((arg0 + (arg1 * 4)), void **, 0x10), s8 *, 0x26) = var_r2;
}
