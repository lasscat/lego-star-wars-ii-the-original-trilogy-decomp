#include "m2c.h"

void func_0207c018(void *arg0, s32 arg1, s32 arg2) {
    u8 temp_r1;

    if (arg1 == 1) {
        return;
    }
    if (arg2 == 1) {
        temp_r1 = M2C_FIELD(arg0, u8 *, 0xDE);
        if (temp_r1 == 0) {
            M2C_FIELD(arg0, s8 *, 0xDF) = 0;
        } else if (temp_r1 == 1) {
            M2C_FIELD(arg0, s8 *, 0xDF) = 1;
        }
    }
    M2C_FIELD(arg0, u8 *, 0xDE) = 2U;
}
