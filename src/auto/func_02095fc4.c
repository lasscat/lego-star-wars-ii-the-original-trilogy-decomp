#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02095fc4 (84 bytes).
 * Appends a 3-byte record to a table and swaps a byte with a side buffer.
 */
void func_02095fc4(s32 a0, s32 a1, s32 a2, s32 a3) {
    *(u8 *) (a0 + *(s32 *) (a0 + 0x304) * 3 + 4) = a2;
    *(u8 *) (a0 + *(s32 *) (a0 + 0x304) * 3 + 5) = a3;
    *(u8 *) (a0 + *(s32 *) (a0 + 0x304) * 3 + 6) = *(u8 *) (*(s32 *) (a0 + 0) + a1);
    *(u8 *) (*(s32 *) (a0 + 0) + a1)             = *(s32 *) (a0 + 0x304);
    *(s32 *) (a0 + 0x304)                        = *(s32 *) (a0 + 0x304) + 1;
}
