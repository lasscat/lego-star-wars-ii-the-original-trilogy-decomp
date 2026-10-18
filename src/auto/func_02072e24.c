/* Reconstructed from USA ARM9 at 0x02072e24 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_02104d20;
extern M2C_UNK data_02104d34;

void func_02072e24(void) {
    s32 var_r2;
    for (var_r2 = 0; var_r2 < 4; var_r2++) {
        ((s32 *) &data_02104d34)[var_r2] = 0;
    }
    M2C_FIELD(&data_02104d20, s32 *, 4) = 0;
}
