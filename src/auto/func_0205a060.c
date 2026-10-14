#include "m2c.h"

M2C_UNK func_0205a0bc(void *, M2C_UNK);             /* extern */
s32 func_0205a348();                                /* extern */
extern s32 (*data_021012ec)(s32, M2C_UNK, M2C_UNK);

void func_0205a060(void *arg0) {
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = func_0205a348();
    if (M2C_FIELD(arg0, u8 *, 9) != 0) {
        return;
    }
    if (temp_r0 == 0) {
        return;
    }
    temp_r0_2                    = data_021012ec(temp_r0, 0, 0);
    M2C_FIELD(arg0, s32 *, 0x10) = temp_r0_2;
    if (temp_r0_2 == 0) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 9) = 1U;
    func_0205a0bc(arg0, 0);
}
