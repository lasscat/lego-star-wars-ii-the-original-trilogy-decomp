#include "m2c.h"

void func_020b3770(void *arg0, u8 arg1) {
    s32 var_r2;
    u8 temp_r3;

    if (M2C_FIELD(arg0, s32 *, 8) != 0) {
        return;
    }
    temp_r3 = M2C_FIELD(arg0, u8 *, 0x10);
    if (temp_r3 == arg1) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 1) == arg1) {
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
        M2C_FIELD(arg0, u8 *, 0x10) = (u8) M2C_FIELD(arg0, u8 *, 1);
        return;
    }
    if (temp_r3 == 0) {
        var_r2 = 0xA;
    } else {
        var_r2 = 0x64;
    }
    M2C_FIELD(arg0, s32 *, 0xC) = var_r2;
    M2C_FIELD(arg0, u8 *, 0x10) = arg1;
}
