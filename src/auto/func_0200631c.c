#include "m2c.h"

void *func_0208dad8();                              /* extern */

s32 func_0200631c(s32 arg0) {
    s32 var_r4;
    s32 var_r5;

    var_r4 = 0;
    var_r5 = 0;
    do {
        if (M2C_FIELD((arg0 + (var_r5 * 2)), u16 *, 0x6E8) != 0xFA) {
            var_r4 |= M2C_FIELD(func_0208dad8(), s32 *, 0xC);
        }
        var_r5 += 1;
    } while (var_r5 < 5);
    return var_r4;
}
