#include "m2c.h"

s32 func_02063948(s32, s32);                                /* extern */
M2C_UNK func_02063a90(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_02063ae0(M2C_UNK, M2C_UNK);            /* extern */

s32 func_0206aad4(void *arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x18);
    if (temp_r0 == 0) {
        if (M2C_FIELD(arg0, u8 *, 0x81) == 0) {
            M2C_FIELD(arg0, u8 *, 0x81) = 1U;
            func_02063ae0(1, 0);
        } else if (func_02063948(1, 0) == 3) {
            if (M2C_FIELD(arg0, u8 *, 0x81) != 1) {
                M2C_FIELD(arg0, u8 *, 0x81) = 0U;
            } else {
                M2C_FIELD(arg0, u8 *, 0x81) = 2U;
                func_02063a90(1, 0);
            }
            return 1;
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) (temp_r0 - 1);
    }
    return 0;
}
