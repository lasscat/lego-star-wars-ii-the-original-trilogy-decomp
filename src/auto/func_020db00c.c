#include "m2c.h"

extern M2C_UNK data_02118960;

void func_020db00c(void) {
    M2C_FIELD(M2C_FIELD(&data_02118960, void **, 0x1C), s16 *, 0x4B0) = 1;
    M2C_FIELD(&data_02118960, u8 *, 0x26) = (u8) M2C_FIELD(M2C_FIELD(&data_02118960, void **, 0x1C), u8 *, 0x4B4);
    M2C_FIELD(&data_02118960, s8 *, 0x24) = 5;
}
