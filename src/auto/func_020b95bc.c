#include "m2c.h"

s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020b95f4(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_020b95bc(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;

    temp_r0 = func_0205e80c(0x1C, 3, 4);
    if (temp_r0 == 0) {
        return;
    }
    func_020b95f4(temp_r0, 0, arg0, arg1);
}
