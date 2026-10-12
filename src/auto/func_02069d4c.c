#include "m2c.h"

s32 func_02085fb8(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_02086184(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02104d90;

s32 func_02069d4c(void *arg0, M2C_UNK arg1) {
    void *temp_r2;
    void *temp_r2_2;

    func_02086184(&data_02104d90);
    if (func_02085fb8(&data_02104d90, arg1) == 0) {
        return 0;
    }
    temp_r2 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r2, s32 *, 0x20) = (s32) (M2C_FIELD(temp_r2, s32 *, 0x20) | 4);
    temp_r2_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24);
    M2C_FIELD(temp_r2_2, u16 *, 8) = (u16) (M2C_FIELD(temp_r2_2, u16 *, 8) | 1);
    return 1;
}
