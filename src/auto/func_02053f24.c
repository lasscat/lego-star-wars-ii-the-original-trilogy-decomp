#include "m2c.h"

void func_02053f24(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((M2C_FIELD(arg0, s32 *, 4) & ~7) | arg1);
    M2C_FIELD(arg0, u8 *, 0x1C) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 1);
}
