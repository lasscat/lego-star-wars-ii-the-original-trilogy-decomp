#include "m2c.h"

void func_020900ec(s32 a0, u32 a1, u8 *a2, u32 *a3) {
    u32 i;
    u32 mask = 1;
    for (i = 0; i < a1; i++) {
        u8 b = a2[i];
        if (b != 0xff) {
            *a3 |= mask << b;
        }
    }
}
