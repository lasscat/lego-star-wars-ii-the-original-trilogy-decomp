#include "m2c.h"

void func_02053f9c(void *arg0, s32 arg1) {
    s32 temp_r1;
    s32 var_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 4);
    if (arg1 != 0) {
        var_r1 = temp_r1 | 0x40000000;
    } else {
        var_r1 = temp_r1 & ~0x40000000;
    }
    M2C_FIELD(arg0, s32 *, 4)   = var_r1;
    M2C_FIELD(arg0, u8 *, 0x1C) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 1);
}
