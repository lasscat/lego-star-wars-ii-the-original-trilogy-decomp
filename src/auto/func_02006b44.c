/* Reconstructed from USA ARM9 at 0x02006b44 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02006b44(s32 *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (arg0[i + 0x1B4] == -1) {
            arg0[i + 0x1B4] = arg1;
            return;
        }
    }
}
