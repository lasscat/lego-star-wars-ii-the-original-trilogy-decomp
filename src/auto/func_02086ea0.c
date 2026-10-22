#include "m2c.h"

extern M2C_UNK data_020f4910;

M2C_UNK func_020865ac(void *, s32);                  /* extern */

typedef struct {
    u8 f0;
    u8 f1;
    s16 f2;
} Entry;

void func_02086ea0(void *base, s32 bit) {
    u32 mask;
    u32 *table;
    s32 index;
    u16 i;

    mask  = 1U << (bit & 0x1F);
    index = bit >> 5;
    table = (u32 *) ((u8 *) base + 0x4520);
    table[index] &= ~mask;
    table[index] |= mask;
    for (i = 0; i < 0xFA; i++) {
        if (((Entry *) &data_020f4910)[i].f0 == 4 && ((Entry *) &data_020f4910)[i].f2 == bit) {
            func_020865ac(base, i);
        }
    }
}
