#include "m2c.h"

s32 func_020608fc(void *arg0) {
    return ((s32) M2C_FIELD(arg0, u16 *, 2) >> 9) & 0x1F;
}
