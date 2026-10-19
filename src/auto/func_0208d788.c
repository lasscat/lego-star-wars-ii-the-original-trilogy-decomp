#include "m2c.h"
s32 func_0208d710(u16);
u32 func_0208d788(s32 arg0) {
    s32 temp_r0;
    s32 var_r5;
    u32 var_r4;
    var_r4 = 0;
    var_r5 = 0;
    do {
        temp_r0 = M2C_FIELD((arg0 + ((u8) var_r5 * 2)), u16 *, 0x6E8);
        if (temp_r0 != 0xFA) {
            var_r4 |= func_0208d710(temp_r0);
        }
        var_r5 += 1;
    } while (var_r5 < 5);
    return var_r4;
}
