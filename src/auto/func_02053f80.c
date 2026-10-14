#include "m2c.h"

void func_02053f80(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4)   = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0xFF00);
    M2C_FIELD(arg0, u8 *, 0x1C) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 1);
}
