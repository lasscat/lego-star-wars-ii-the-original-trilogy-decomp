#include "m2c.h"

M2C_UNK func_020d1240(M2C_UNK, M2C_UNK);            /* extern */
s32 func_020d65b4();                                /* extern */
s32 func_020d6618(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020d6a58();                            /* extern */
extern M2C_UNK data_02117e20;

s32 func_020d63c8(void) {
    s32 temp_r0;

    if (func_020d65b4() != 0) {
        return 3;
    }
    temp_r0 = func_020d6618(1, 0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020d6a58();
    func_020d1240(0xA, 0);
    M2C_FIELD(&data_02117e20, s32 *, 4) = 0;
    M2C_FIELD(&data_02117e20, s16 *, 0) = 0;
    return 0;
}
