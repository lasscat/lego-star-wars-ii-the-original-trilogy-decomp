#include "m2c.h"

M2C_UNK func_0200c724(s32, u16, u8, s8);            /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */

void func_02059504(M2C_UNK arg0, void *arg1) {
    s32 temp_r0;
    u8 temp_r2;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 2), M2C_FIELD(arg1, u8 *, 3));
    if (temp_r0 == 0) {
        return;
    }
    temp_r2 = M2C_FIELD(arg1, u8 *, 4);
    func_0200c724(temp_r0, M2C_FIELD(arg1, u16 *, 0), temp_r2, (s8) temp_r2);
}
