/* Reconstructed from USA ARM9 at 0x0205a2a8 (160 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0205a2a8(void *arg0) {
    switch ((s32) M2C_FIELD(arg0, u16 *, 6)) {
        case 0x8:
        default:
            return 0;
        case 0x10:
            return 1;
        case 0x20:
            return 2;
        case 0x40:
            return 3;
        case 0x80:
            return 4;
        case 0x100:
            return 5;
        case 0x200:
            return 6;
        case 0x400:
            return 7;
    }
}
