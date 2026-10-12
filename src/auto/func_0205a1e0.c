#include "m2c.h"

s32 func_0205a1e0(void *arg0, s32 arg1, s32 arg2) {
    return (arg2 * ((s32) M2C_FIELD(arg0, u16 *, 4) >> 1)) + (arg1 >> 1);
}
