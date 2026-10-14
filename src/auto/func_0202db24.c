#include "m2c.h"

M2C_UNK func_0202c1a8(s32, s32);                    /* extern */
s32 func_0203668c(s32, s32, M2C_UNK, M2C_UNK);      /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

s32 func_0202db24(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = func_0205e80c(0x24, 1, 4);
    var_r4  = temp_r0;
    if (var_r4 != 0) {
        var_r4 = func_0203668c(temp_r0, arg0, arg1, arg2);
    }
    func_0202c1a8(arg0 + 0x5E0, var_r4);
    return var_r4;
}
