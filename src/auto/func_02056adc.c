#include "m2c.h"

s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */
M2C_UNK func_02094244(s32, s32, M2C_UNK, u8, s32);  /* extern */

void func_02056adc(M2C_UNK arg0, void *arg1) {
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == 0) {
        return;
    }
    temp_r0_2 = func_0205e80c(0x10, 0, 4);
    if (temp_r0_2 == 0) {
        return;
    }
    func_02094244(temp_r0_2, temp_r0, 0, M2C_FIELD(arg1, u8 *, 2), 1);
}
