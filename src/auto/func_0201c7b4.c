/* Reconstructed from USA ARM9 at 0x0201c7b4 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0201c7b4(u16 *arg0, u16 *arg1) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (arg0[i + 1] != arg1[i + 1]) {
            return 0;
        }
    }
    return 1;
}
