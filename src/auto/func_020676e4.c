/* Reconstructed from USA ARM9 at 0x020676e4 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020676e4(s32 arg0, s32 arg1) {
    s32 r = arg1 & 3;
    if (r == 1) {
        r = 3;
    } else if (r == 2) {
        r = 2;
    } else if (r == 3) {
        r = 1;
    }
    return arg1 + r;
}
