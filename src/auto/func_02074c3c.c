#include "m2c.h"

void func_02074c3c(void *a0, s32 *a1, s32 a2) {
    M2C_FIELD(a0, u8 *, 0x0)   = 0;
    M2C_FIELD(a0, s32 *, 0x10) = 0;
    M2C_FIELD(a0, s32 *, 0x14) = a1[0];
    M2C_FIELD(a0, s32 *, 0x18) = a1[1];
    M2C_FIELD(a0, s32 *, 0x1c) = a1[2];
    M2C_FIELD(a0, s32 *, 0x20) = *(s32 *) &a2;
    M2C_FIELD(a0, s32 *, 0x24) = 0;
    M2C_FIELD(a0, s32 *, 0x28) = 0;
}
