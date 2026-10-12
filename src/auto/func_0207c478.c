#include "m2c.h"

void func_0207c478(void *arg0, s32 arg1) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r2 >= 8) {
        return;
    }
    M2C_FIELD((arg0 + (temp_r2 * 4)), s32 *, 8) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 1);
}
