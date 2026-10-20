#include "m2c.h"

void func_02074c7c(volatile u8 *base, s32 index, s32 clear) {
    volatile u8 *p = base + 2;
    u32 value;
    if (clear) {
        value = p[index * 2] & ~0x40;
    } else {
        value = p[index * 2] | 0x40;
    }
    p[index * 2] = value;
}
