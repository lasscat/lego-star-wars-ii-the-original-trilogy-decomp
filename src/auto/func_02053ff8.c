#include "m2c.h"

void func_02053ff8(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) ((M2C_FIELD(arg0, u16 *, 0xA) & 0xC0) | arg1 | (arg2 << 8));
    M2C_FIELD(arg0, u8 *, 0x1C) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 4);
}
