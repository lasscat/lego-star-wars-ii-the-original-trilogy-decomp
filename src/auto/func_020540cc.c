#include "m2c.h"

void func_020540cc(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x10) = arg1;
    M2C_FIELD(arg0, s16 *, 0x14) = arg2;
    M2C_FIELD(arg0, u8 *, 0x1C)  = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 8);
}
