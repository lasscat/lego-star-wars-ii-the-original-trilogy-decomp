#include "m2c.h"

void func_0201b254(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((M2C_FIELD(arg0, s32 *, 0x14) & ~0xC00) | ((u32) (arg1 << 0x1E) >> 0x14));
}
