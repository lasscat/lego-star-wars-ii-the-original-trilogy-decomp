#include "m2c.h"

s32 func_020d7190(s32);                             /* extern */
M2C_UNK func_020dce78(M2C_UNK, s32);                /* extern */
extern M2C_UNK data_0211e400;

s32 func_020dca0c(void) {
    s32 var_r4;

    var_r4 = func_020d7190(M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s32 *, 0x508));
    func_020dce78(1, var_r4);
    if (var_r4 == 2) {
        var_r4 = 0;
    }
    return var_r4;
}
