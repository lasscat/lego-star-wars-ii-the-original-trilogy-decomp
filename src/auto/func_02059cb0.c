#include "m2c.h"

M2C_UNK func_020108f4(void *, M2C_UNK, M2C_UNK);    /* extern */
void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_02059cb0(M2C_UNK arg0, void *arg1) {
    M2C_UNK var_r2;
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (!(M2C_FIELD(temp_r0, s32 *, 8) & 0x100000)) {
        return;
    }
    var_r2 = 0;
    if ((M2C_FIELD(arg1, u8 *, 3) == 0) && (M2C_FIELD(temp_r0, s32 *, 0x1B8) & 0x300)) {
        var_r2 = 2;
    }
    M2C_FIELD(temp_r0, u8 *, 0x1AE) = (u8) M2C_FIELD(arg1, u8 *, 2);
    func_020108f4(temp_r0, 1, var_r2);
}
