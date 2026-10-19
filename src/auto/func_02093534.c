/* Reconstructed from USA ARM9 at 0x02093534 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s8 func_02093534(s32 arg0, s32 arg1) {
    s32 t;
    u32 var_r3;

    var_r3 = 0;
    do {
        t = M2C_FIELD((arg0 + (var_r3 * 4)), s32 *, 0x4C);
        if (t == arg1) {
            return (s8) var_r3;
        }
        var_r3 = (u8) (var_r3 + 1);
    } while (var_r3 < 4U);
    return -1;
}
