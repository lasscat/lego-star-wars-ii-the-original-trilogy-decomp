/* Reconstructed from USA ARM9 at 0x020b9310 (80 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020bb36c(s32);                             /* extern */
s32 func_020bb918();                                /* extern */
extern u8 data_0210dd54;

s32 func_020b9310(s32 arg0) {
    s32 var_r5;
    u8 *var_r6;
    s32 temp_r4;

    var_r6 = &data_0210dd54;
    var_r5 = 0xB;
    do {
        if (arg0 == M2C_FIELD(var_r6, s32 *, 0x3C)) {
            temp_r4 = func_020bb36c(var_r5);
            if (func_020bb918() != 0) {
                return temp_r4;
            }
        }
        var_r6 -= 0x1C;
        var_r5 -= 1;
    } while (var_r5 >= 0);
    return -1;
}
