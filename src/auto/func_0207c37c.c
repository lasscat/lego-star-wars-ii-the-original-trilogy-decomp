#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02065be8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(M2C_UNK);                         /* extern */

void func_0207c37c(s32 arg0, s32 arg1) {
    M2C_UNK var_r1;

    if (arg1 != 0) {
        var_r1 = 3;
    } else {
        var_r1 = 0;
    }
    func_0206574c(arg0 + 0x38, var_r1, 0);
    func_02065be8(arg0 + 0x38, 0x181, 0x80, 0x90, func_02066708(0x58), 1);
}
