/* Reconstructed from USA ARM9 at 0x0209419c (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020940c4();                            /* extern */

void func_0209419c(void *arg0) {
    s32 temp_r1;

    temp_r1                  = M2C_FIELD(arg0, u8 *, 9) - 1;
    M2C_FIELD(arg0, u8 *, 9) = (u8) temp_r1;
    if (temp_r1 & 0xFF) {
        return;
    }
    func_020940c4();
}
