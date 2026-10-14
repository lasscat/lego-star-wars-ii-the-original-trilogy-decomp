#include "m2c.h"

void func_0209435c(void *arg0, void *arg1, s16 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0)    = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 4)    = (s32) M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 8)    = (s32) M2C_FIELD(arg1, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0xC)  = arg3;
    M2C_FIELD(arg0, s16 *, 0x10) = arg2;
}
