#include "m2c.h"

void func_020b3b38(void *arg0, u8 arg1, s8 arg2) {
    u8 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u8 *, 1);
    if (temp_r3 == 1) {
        if (M2C_FIELD(arg0, u8 *, 0x3A) == arg1) {
            M2C_FIELD(arg0, s8 *, 0x39) = 1;
        } else {
            M2C_FIELD(arg0, s8 *, 0x39) = 2;
            M2C_FIELD(arg0, u8 *, 0x3B) = arg1;
            M2C_FIELD(arg0, s8 *, 0x3D) = arg2;
        }
    } else if (temp_r3 == 2) {
        if (M2C_FIELD(arg0, u8 *, 0x3B) == arg1) {
            M2C_FIELD(arg0, s8 *, 0x39) = 2;
        } else {
            M2C_FIELD(arg0, s8 *, 0x39) = 1;
            M2C_FIELD(arg0, u8 *, 0x3A) = arg1;
            M2C_FIELD(arg0, s8 *, 0x3C) = arg2;
        }
    } else {
        M2C_FIELD(arg0, s8 *, 0x39) = 1;
        M2C_FIELD(arg0, u8 *, 0x3A) = arg1;
        M2C_FIELD(arg0, s8 *, 0x3C) = arg2;
    }
    M2C_FIELD(arg0, s8 *, 0x38) = 2;
}
