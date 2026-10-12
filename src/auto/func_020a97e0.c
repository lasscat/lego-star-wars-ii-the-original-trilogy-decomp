#include "m2c.h"

s32 func_020a97e0(s32 arg0, void *arg1, void *arg2) {
    s32 temp_r1;
    s32 temp_r3;

    temp_r3 = ((s32) M2C_FIELD(arg2, s32 *, 0) >> 0xC) - M2C_FIELD(arg1, s16 *, 0);
    temp_r1 = ((s32) M2C_FIELD(arg2, s32 *, 8) >> 0xC) - M2C_FIELD(arg1, s16 *, 4);
    return (temp_r1 * temp_r1) + (temp_r3 * temp_r3);
}
