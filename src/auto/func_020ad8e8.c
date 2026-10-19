/* Reconstructed from USA ARM9 at 0x020ad8e8 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"
extern M2C_UNK data_0210bf40;
s32 func_020ad8e8(void) {
    s32 var_r0;
    s32 var_r2;
    s8 *var_r3;
    var_r0 = 0;
    var_r2 = 0;
    var_r3 = (s8 *) &data_0210bf40;
    do {
        var_r2 += 1;
        if (M2C_FIELD(var_r3, s32 *, 0xC0) != 0) {
            var_r0 += 1;
        }
        var_r3 += 0xC4;
    } while (var_r2 < 0x10);
    return var_r0;
}
