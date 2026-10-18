/* Reconstructed from USA ARM9 at 0x02093b70 (104 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020111b0(s32, s32);                        /* extern */
s32 func_0204a880(s32);                             /* extern */

s32 func_02093b70(s32 *arg0, void *arg1) {
    s32 temp_r0;
    s32 var_r4;

    var_r4 = 0;
    do {
        temp_r0 = arg0[0x13 + var_r4];
        if ((temp_r0 != 0) && (func_0204a880(temp_r0 + 0x5CE) == 0) &&
            (func_020111b0(arg0[0x13 + var_r4], M2C_FIELD(arg1, s32 *, 0x194)) != 0)) {
            return arg0[0x13 + var_r4];
        }
        var_r4 += 1;
    } while (var_r4 < 4);
    return 0;
}
