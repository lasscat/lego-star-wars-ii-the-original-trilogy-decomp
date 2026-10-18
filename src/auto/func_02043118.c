/* Reconstructed from USA ARM9 at 0x02043118 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02043118(s32 arg0) {
    u32 temp_r0 = arg0 - 0x21;

    switch (temp_r0) {
        case 0:
        case 1:
        case 2:
        case 3:
            return 1;
        default:
            return 0;
    }
}
