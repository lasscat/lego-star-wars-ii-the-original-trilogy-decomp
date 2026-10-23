#include "m2c.h"

s32 func_0203745c(void *a0, s32 a1, u32 a2, ...) {
    if (a1 == 8) {
        *(u16 *) ((u8 *) a0 + 0xe) = *(u32 *) &a2;
        return 1;
    }
    return 0;
}
