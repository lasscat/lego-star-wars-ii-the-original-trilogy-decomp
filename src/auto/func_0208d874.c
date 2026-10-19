#include "m2c.h"

s32 func_0208d710(u16);                             /* extern */
M2C_UNK func_0208d7d4(M2C_UNK, s32);                /* extern */

void func_0208d874(M2C_UNK arg0, u16 *arg1) {
    s32 temp_r0;
    u32 var_r4;
    u8 var_r5;

    var_r4 = 0;
    var_r5 = 0;
    if (*arg1 != 0xFA) {
        do {
            temp_r0 = func_0208d710(arg1[var_r5]);
            var_r5 += 1;
            var_r4 |= temp_r0;
        } while (arg1[var_r5] != 0xFA);
    }
    func_0208d7d4(arg0, var_r4);
}
