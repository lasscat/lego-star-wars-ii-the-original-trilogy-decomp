#include "m2c.h"

s32 func_020bba5c(s32);                             /* extern */

void func_020bda0c(void *arg0, void *arg1) {
    s32 temp_r4;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 var_r0;
    s32 var_r0_2;

    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    if (M2C_FIELD(arg1, u8 *, 0x4C) != 0) {
        var_r0 = (M2C_FIELD(arg1, u8 *, 0x4D) * M2C_FIELD(arg1, s32 *, 0x48)) - M2C_FIELD(arg1, s32 *, 0x68);
    } else {
        temp_r6 = M2C_FIELD(arg1, s32 *, 0x68);
        var_r0 = func_020bba5c(temp_r6 * 2) - temp_r6;
    }
    M2C_FIELD(arg0, s32 *, 0) = var_r0;
    if (M2C_FIELD(arg1, u8 *, 0x54) != 0) {
        var_r0_2 = (M2C_FIELD(arg1, u8 *, 0x55) * M2C_FIELD(arg1, s32 *, 0x50)) - M2C_FIELD(arg1, s32 *, 0x6C);
    } else {
        temp_r6_2 = M2C_FIELD(arg1, s32 *, 0x6C);
        var_r0_2 = func_020bba5c(temp_r6_2 * 2) - temp_r6_2;
    }
    M2C_FIELD(arg0, s32 *, 4) = var_r0_2;
    if (M2C_FIELD(arg1, u8 *, 0x5C) != 0) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) ((M2C_FIELD(arg1, u8 *, 0x5D) * M2C_FIELD(arg1, s32 *, 0x58)) - M2C_FIELD(arg1, s32 *, 0x70));
        return;
    }
    temp_r4 = M2C_FIELD(arg1, s32 *, 0x70);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (func_020bba5c(temp_r4 * 2) - temp_r4);
}
