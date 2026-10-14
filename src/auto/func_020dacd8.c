#include "m2c.h"

M2C_UNK func_020dad04();                            /* extern */
extern M2C_UNK data_02118960;

void func_020dacd8(void) {
    M2C_FIELD(&data_02118960, s32 *, 0x18) = 0;
    M2C_FIELD(&data_02118960, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_02118960, s8 *, 0x24)  = 1;
    M2C_FIELD(&data_02118960, s32 *, 0x14) = 0;
    func_020dad04();
}
