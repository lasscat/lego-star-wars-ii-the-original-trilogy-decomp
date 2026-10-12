#include "m2c.h"

M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
s32 func_02066ff0(M2C_UNK, u8, M2C_UNK);            /* extern */
M2C_UNK func_0206dd60();                            /* extern */
extern M2C_UNK data_02102900;

void func_02057194(M2C_UNK arg0, u8 *arg1) {
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = func_02066ff0(arg0, *arg1, 0);
    if (M2C_FIELD(&data_02102900, void **, 4) != NULL) {
        var_r0 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 4), s32 *, 4);
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0x1E) {
        return;
    }
    func_0206dd60();
    func_0205ecc4(&data_02102900, 0x1E, 1, temp_r4, 0, 0);
    M2C_FIELD(&data_02102900, s32 *, 0x84) = 1;
}
