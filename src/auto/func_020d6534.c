#include "m2c.h"

M2C_UNK func_020cd900(M2C_UNK *, s32, M2C_UNK);     /* extern */
M2C_UNK func_020cdd20(s32, M2C_UNK);                /* extern */
M2C_UNK func_020cf3dc(M2C_UNK, s32, M2C_UNK);       /* extern */
s32 func_020d12b0(M2C_UNK, s32, M2C_UNK);           /* extern */
s32 func_020d6430();                                /* extern */
extern M2C_UNK data_02117e28;

s32 func_020d6534(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    s32 temp_r4;

    temp_r0 = func_020d6430();
    if (temp_r0 == 0) {
        return 8;
    }
    func_020cf3dc(arg0, temp_r0, arg1);
    func_020cdd20(temp_r0, arg1);
    temp_r4 = func_020d12b0(0xA, temp_r0, 0);
    func_020cd900(&data_02117e28, temp_r0, 1);
    if (temp_r4 < 0) {
        return 8;
    }
    return 2;
}
