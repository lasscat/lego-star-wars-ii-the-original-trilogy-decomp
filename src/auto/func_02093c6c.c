/* Reconstructed from USA ARM9 at 0x02093c6c (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 data_027e02a8;

void func_02093c6c(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        data_027e02a8 |= 3;
    } else {
        data_027e02a8 &= ~3;
    }
}
