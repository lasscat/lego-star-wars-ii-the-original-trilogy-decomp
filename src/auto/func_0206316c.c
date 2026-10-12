#include "m2c.h"

M2C_UNK func_02063074();                            /* extern */
s32 func_02063418(M2C_UNK);                         /* extern */
s32 func_02063510(s32, M2C_UNK);                    /* extern */
extern M2C_UNK data_02104364;

s32 func_0206316c(M2C_UNK arg0) {
    s32 var_r0;

    func_02063074();
    if (func_02063418(arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        return var_r0;
    }
    if (func_02063510(M2C_FIELD(&data_02104364, s32 *, 0x20), 0xA0) == 0) {
        return 1;
    }
    return 0;
}
