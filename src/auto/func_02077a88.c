#include "m2c.h"

M2C_UNK func_0205365c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(s32, s32, s32, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */

void func_02077a88(s32 arg0) {
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r4 = 0x29;
    func_0205365c(arg0 + 0x28, 0);
    func_0206574c(arg0 + 0xA0, 9, -1);
    func_02065be8(arg0 + 0xA0, 1, 0x80, 0x3D, func_02066708(0x15E), 1);
    var_r5 = 0;
    var_r6 = 0x28;
    do {
        temp_r0 = func_02065be8(arg0 + 0xA0, var_r4, var_r6, 0x68,
                                func_02066708(M2C_FIELD((arg0 + var_r5), s8 *, 0x145) + 0x268), 1);
        var_r5 += 1;
        var_r4 = temp_r0;
        var_r6 += 0x23;
    } while (var_r5 < 6);
}
