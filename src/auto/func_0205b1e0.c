#include "m2c.h"

/*
 * Updates the packed value at offset 8 of the object pointed to by a1.
 *
 * The word holds a 7-bit field at bits 16..22 and a flag at bit 23.
 *   a2 != 0 and the flag is clear: set the flag, clear the 7-bit field and
 *                            store 1 in it.
 *   a2 != 0 and the flag is set:  increment the 7-bit field (mod 128).
 *   a2 == 0 and the flag is clear: clear the 7-bit field and store 80 in it.
 */
void func_0205b1e0(s32 a0, s32 a1, s32 a2) {
    u32 *p = (u32 *) (a1 + 8);

    if (a2 != 0) {
        if (((*p) << 8) >> 31 == 0) {
            *p |= 0x800000;
            *p = (*p & ~0x7f0000) | 0x10000;
        } else {
            u32 c = (*p << 9) >> 25;
            *p    = (*p & ~0x7f0000) | (((c + 1) & 0x7f) << 16);
        }
    } else {
        if (((*p) << 8) >> 31 == 0) {
            *p &= ~0x7f0000;
            *p |= 0xa0000;
        }
    }
}
