#include "m2c.h"

u8 func_02066c18(u32);

void func_02066b4c(u16 *src, u32 count, u8 *dst) {
    u32 i;
    for (i = 0; i < count; i++) {
        dst[i] = func_02066c18(src[i]);
    }
}
