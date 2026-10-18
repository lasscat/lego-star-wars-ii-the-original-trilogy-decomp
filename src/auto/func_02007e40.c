/* Reconstructed from USA ARM9 at 0x02007e40 (108 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02007e40(void *arg0) {
    switch (M2C_FIELD(arg0, u16 *, 0x6F0) - 0xE9) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 13:
        case 15:
        case 16:
            return 1;
        case 1:
        case 5:
        case 6:
        case 9:
        case 14:
        default:
            return 0;
    }
}
