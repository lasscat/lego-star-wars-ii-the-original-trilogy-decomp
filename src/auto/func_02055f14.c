#include "m2c.h"

M2C_UNK func_02057cf8(M2C_UNK, s32, u8, u8);        /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */

void func_02055f14(M2C_UNK arg0, void *arg1) {
    s32 temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == 0) {
        return;
    }
    func_02057cf8(arg0, temp_r0, M2C_FIELD(arg1, u8 *, 2), M2C_FIELD(arg1, u8 *, 3));
}
