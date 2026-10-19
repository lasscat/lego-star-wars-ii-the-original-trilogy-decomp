/* Reconstructed from USA ARM9 at 0x020263a8 (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

u8 func_02016c30();                                 /* extern */

u8 func_020263a8(void *arg0) {
    u32 temp_r1 = M2C_FIELD(arg0, u16 *, 0x212) - 0xBD;

    switch (temp_r1) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return M2C_FIELD(arg0, u8 *, 0x1BC);
        default:
            return func_02016c30();
    }
}
