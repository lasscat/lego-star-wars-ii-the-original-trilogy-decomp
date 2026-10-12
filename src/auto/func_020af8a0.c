#include "m2c.h"

s32 func_020af8a0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0x6F8) = arg1;
    M2C_FIELD(arg0, s32 *, 0x6FC) = arg2;
    M2C_FIELD(arg0, s32 *, 0x700) = arg3;
    return 1;
}
