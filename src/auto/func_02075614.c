#include "m2c.h"

void func_02075614(u32 *a0, u32 a1, s32 a2) {
    u32 *w   = a0 + (a1 >> 5);
    u32 mask = 1U << (a1 & 31);
    if (a2 != 0) {
        *w |= mask;
    } else {
        *w &= ~mask;
    }
}
