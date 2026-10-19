/* Reconstructed from USA ARM9 at 0x0204a590 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

u8 func_0204a590(void *arg0, u16 *arg1) {
    volatile u16 sp0;
    u8 temp_r2;
    u16 temp_r2_2;

    temp_r2 = M2C_FIELD(arg0, u8 *, 0xD);
    if (temp_r2 != 0) {
        temp_r2_2 = M2C_FIELD(arg0, u16 *, 0xE);
        *arg1     = temp_r2_2;
        sp0       = temp_r2_2;
    }
    return M2C_FIELD(arg0, u8 *, 0xD);
}
