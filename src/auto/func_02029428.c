#include "m2c.h"

M2C_UNK func_0202c1a8(s32, s32);                    /* extern */
s32 func_02037394(s32, s32, M2C_UNK);               /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void func_02029428(s32 arg0) {
    s32 temp_r0;
    s32 var_r1;

    if (arg0 == 0) {
        return;
    }
    temp_r0 = func_0205e80c(0x10, 1, 4);
    var_r1  = temp_r0;
    if (var_r1 != 0) {
        var_r1 = func_02037394(temp_r0, arg0, 0);
    }
    func_0202c1a8(arg0 + 0x5E0, var_r1);
}
