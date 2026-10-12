#include "m2c.h"

s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02072e24();                            /* extern */
s32 func_020ad354();                                /* extern */
extern M2C_UNK data_0210b320;

void func_020ad320(void) {
    s32 var_r0;

    var_r0 = func_0205e80c(4, 3, 4);
    if (var_r0 != 0) {
        var_r0 = func_020ad354();
    }
    M2C_FIELD(&data_0210b320, s32 *, 0x28) = var_r0;
    func_02072e24();
}
