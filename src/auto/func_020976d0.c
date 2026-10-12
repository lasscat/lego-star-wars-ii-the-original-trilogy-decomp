#include "m2c.h"

void func_020976d0(void *arg0, s8 arg1, s8 arg2, s32 arg3) {
    M2C_FIELD(arg0, s8 *, 0x2D) = arg1;
    M2C_FIELD(arg0, s8 *, 0x39) = arg2;
    M2C_FIELD(arg0, s32 *, 0x30) = arg3;
}
