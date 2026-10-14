#include "m2c.h"

void func_0201d884(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x1C4) = 0;
    M2C_FIELD(arg0, s32 *, 8)     = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~1);
}
