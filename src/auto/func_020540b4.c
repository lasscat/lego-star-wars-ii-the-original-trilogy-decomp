#include "m2c.h"

void func_020540b4(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x18) = arg1;
    M2C_FIELD(arg0, s16 *, 0x1A) = arg2;
    M2C_FIELD(arg0, u8 *, 0x1C) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 8);
}
