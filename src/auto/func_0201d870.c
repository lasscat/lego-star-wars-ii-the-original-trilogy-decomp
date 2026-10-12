#include "m2c.h"

void func_0201d870(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1C4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 1);
}
