/* Reconstructed from USA ARM9 at 0x0208c7b0 (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0208c77c(M2C_UNK, u32);                    /* extern */

u32 func_0208c7b0(M2C_UNK arg0) {
    u32 count;
    u32 i;

    count = 0;
    i     = 0;
    do {
        if (func_0208c77c(arg0, i) != 0) {
            count += 1;
        }
        i += 1;
    } while (i < 0x10U);
    return count;
}
