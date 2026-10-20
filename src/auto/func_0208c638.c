#include "m2c.h"

void func_0208c638(s32 a0, s32 a1, s32 a2) {
    s32 v;
    u32 mask;
    s32 index;
    u32 *table;

    v     = a1 * 11 + a2;
    mask  = 1U << (v & 0x1F);
    index = v >> 5;
    table = (u32 *) a0;
    table[index] &= ~mask;
    table[index] |= mask;
    ((u8 *) a0)[0x19]++;
}
