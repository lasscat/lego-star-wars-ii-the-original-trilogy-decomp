#include "m2c.h"

M2C_UNK func_020d6418(M2C_UNK, M2C_UNK);            /* extern */
s32 func_020d6488(M2C_UNK, M2C_UNK);                /* extern */
s32 func_020d6618(M2C_UNK, M2C_UNK);                /* extern */

s32 func_020d71c8(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020d6618(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020d6418(2, arg0);
    var_r0 = func_020d6488(2, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
