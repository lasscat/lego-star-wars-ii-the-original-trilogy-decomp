/* Reconstructed from USA ARM9 at 0x02066b84 (56 bytes).
 * Converts an array of bytes into an array of u16 codes.
 */
#include "m2c.h"

u32 func_02066bbc(u32 arg0); /* extern */

void func_02066b84(u8 *arg0, u32 arg1, u16 *arg2) {
    u32 i;
    for (i = 0; i < arg1; i++) {
        arg2[i] = func_02066bbc(arg0[i]);
    }
}
