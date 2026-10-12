#include "m2c.h"

void func_02053fc0(void *arg0, s32 arg1) {
    if (arg1 < 0) {
        M2C_FIELD(arg0, s16 *, 8) = (s16) ((0 - arg1) | 0x8000);
    } else if (arg1 > 0) {
        M2C_FIELD(arg0, s16 *, 8) = (s16) (arg1 | 0x4000);
    } else {
        M2C_FIELD(arg0, s16 *, 8) = 0;
    }
    M2C_FIELD(arg0, u8 *, 0x1C) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 2);
}
