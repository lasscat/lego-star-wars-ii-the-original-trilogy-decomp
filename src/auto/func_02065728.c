#include "m2c.h"

void func_02065728(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x20) = arg2;
    M2C_FIELD(arg0, s32 *, 0x24) = arg3;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) ((arg4 + 1) << 5);
    M2C_FIELD(arg0, s32 *, 0x2C) = arg4;
}
