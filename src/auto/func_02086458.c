#include "m2c.h"

s32 func_02086588(s32, s32);                         /* extern */
void func_020865ac(M2C_UNK, M2C_UNK);                /* extern */
void func_02086600(M2C_UNK, M2C_UNK);                /* extern */

extern u8 data_020eedac[];
extern u8 data_020eebb8[];
extern u8 data_020ef581[];

void func_02086458(void *base, s32 bit) {
    u32 mask;
    u32 *table;
    s32 index;
    u8 i;
    u16 v;
    u8 b;

    mask  = 1U << (bit & 0x1F);
    index = bit >> 5;
    table = (u32 *) ((u8 *) base + 0x44CC);
    table[index] &= ~mask;
    table[index] |= mask;

    if (func_02086588((s32) base, bit)) {
        table = (u32 *) ((u8 *) base + 0x44DC);
        table[index] &= ~mask;
    }

    for (i = 0; i < 5; i++) {
        v = *(u16 *) ((u8 *) data_020eedac + bit * 20 + i * 2 + 8);
        if (v != 0xfa) {
            func_020865ac(base, v);
        }
        b = *(u8 *) ((u8 *) data_020eebb8 + bit * 5 + i);
        if (b != 0xfa) {
            func_020865ac(base, b);
        }
    }

    b = *(u8 *) ((u8 *) data_020ef581 + bit * 24);
    if (b != 0x28) {
        func_02086600(base, b);
    }
}
