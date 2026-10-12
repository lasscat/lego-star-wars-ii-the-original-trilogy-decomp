#include "m2c.h"

void func_020b3ac4(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x40) = arg1;
    M2C_FIELD(arg0, s8 *, 0x3F) = 1;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0x11) = 0;
}
