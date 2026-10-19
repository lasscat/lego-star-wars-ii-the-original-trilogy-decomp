/* Reconstructed from USA ARM9 at 0x02036970 (96 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02029664(s32, s32);                    /* extern */

void func_02036970(void *arg0) {
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r2;

    var_r1 = M2C_FIELD(arg0, s32 *, 0x10);
    if (var_r1 != 0) {
        var_r1 -= 4;
    }
    if (var_r1 != 0) {
        var_r2   = M2C_FIELD(arg0, s32 *, 0x18);
        var_r1_2 = var_r2;
        if (var_r2 != 0) {
            var_r1_2 = var_r2 - 4;
        }
        if (var_r1_2 != 0) {
            if (var_r2 != 0) {
                var_r2 -= 4;
            }
            func_02029664(M2C_FIELD(arg0, s32 *, 4) + 0x608, var_r2 + 0xB0);
            return;
        }
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
}
