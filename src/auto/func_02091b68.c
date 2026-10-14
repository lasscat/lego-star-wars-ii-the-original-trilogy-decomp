#include "m2c.h"

void func_02091b68(s32 arg0, s32 arg1) {
    void *temp_r2;
    void *temp_r3;

    temp_r3                           = arg0 + (arg1 * 4);
    temp_r2                           = M2C_FIELD(temp_r3, void **, 0x4C);
    M2C_FIELD(temp_r2, s32 *, 8)      = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 2);
    M2C_FIELD(temp_r3, void **, 0x4C) = NULL;
}
