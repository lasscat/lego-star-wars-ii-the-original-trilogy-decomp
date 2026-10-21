#include "m2c.h"

void func_0205a3b0(u16 *a0, s32 a1, u16 *a2, s32 a3) {
    u16 *src = (u16 *) ((u8 *) a0 + a1 * 32);
    s32 i;
    for (i = 0; i < 16; i += 2) {
        a2[0] = src[i];
        a2[1] = src[i + 1];
        a2 += a3;
    }
}
