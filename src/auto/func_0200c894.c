#include "m2c.h"

void func_0200c894(s32 arg0, s32 arg1) {
    s32 temp_r2;
    s32 temp_r3;

    temp_r3                     = arg1 * 0x38;
    temp_r2                     = arg0 + 0x3D0;
    *(s8 *) (temp_r2 + temp_r3) = *(s8 *) (temp_r2 + temp_r3) - 1;
    if (*(s8 *) (temp_r2 + temp_r3) == 0) {
        M2C_FIELD((arg0 + temp_r3), s8 *, 0x3CD) = 0;
    }
}