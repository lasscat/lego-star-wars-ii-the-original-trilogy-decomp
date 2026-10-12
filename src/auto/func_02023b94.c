#include "m2c.h"

void func_02023b94(void *arg0, s8 arg1, s8 arg2, s8 arg3, u16 arg4) {
    M2C_FIELD(arg0, s8 *, 0x1DF) = arg1;
    M2C_FIELD(arg0, s8 *, 0x1DE) = arg2;
    M2C_FIELD(arg0, s8 *, 0x221) = arg3;
    M2C_FIELD(arg0, s8 *, 0x222) = (s8) arg4;
}
