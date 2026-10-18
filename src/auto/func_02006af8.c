/* Reconstructed from USA ARM9 at 0x02006af8 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02006af8(s32 *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (arg1 == arg0[i + 0x1B4]) {
            return 1;
        }
    }
    return 0;
}
