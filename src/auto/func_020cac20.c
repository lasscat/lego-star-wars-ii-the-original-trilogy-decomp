#include "m2c.h"

void *func_020cac20(void) {
    s32 block;
    u32 offset;

    block  = (*(volatile u16 *) 0x0400000A & 0x3C) >> 2;
    offset = (*(volatile u32 *) 0x04000000 & 0x7000000) >> 24;
    return (void *) (0x6000000 + offset * 0x10000 + block * 0x4000);
}
