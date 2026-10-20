#include "m2c.h"

void func_02086e1c(void *base, s32 bit) {
    u32 mask;
    u32 *table;
    s32 index;

    mask  = 1U << (bit & 0x1F);
    index = bit >> 5;
    table = (u32 *) ((u8 *) base + 0x451C);
    table[index] &= ~mask;
    table[index] |= mask;
}
