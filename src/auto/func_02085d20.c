#include "m2c.h"

M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_02085fb8(void *, u8);                  /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104364;

s32 func_02085d20(void *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x443C) != 0) {
        func_02085fb8(arg0, M2C_FIELD(&data_02104364, u8 *, 0x4E));
        return 1;
    }
    func_0205ecc4(&data_02102900, 0x13, 1, arg1, 0, 0);
    M2C_FIELD(arg0, s8 *, 0x2BB5) = 1;
    return 0;
}
