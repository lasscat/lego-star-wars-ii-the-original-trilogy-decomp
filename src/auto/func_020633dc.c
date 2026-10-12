#include "m2c.h"

s32 func_02063510(s32, M2C_UNK);                    /* extern */
extern M2C_UNK data_02104364;
extern M2C_UNK data_021043ac;

s8 func_020633dc(s32 arg0) {
    s8 var_r4;

    var_r4 = 0;
    if (func_02063510(M2C_FIELD(&data_02104364, s32 *, 0x20), 0xA0) == 0) {
        var_r4 = 1;
    }
    ((s8 *)&data_021043ac)[arg0] = var_r4;
    return var_r4;
}
