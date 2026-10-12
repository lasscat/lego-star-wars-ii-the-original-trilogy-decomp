#include "m2c.h"

M2C_UNK func_0200b7f4(s32, M2C_UNK);                /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */

void func_0205654c(M2C_UNK arg0, void *arg1) {
    M2C_UNK var_r1;
    s32 temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == 0) {
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 2) != 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    func_0200b7f4(temp_r0, var_r1);
}
