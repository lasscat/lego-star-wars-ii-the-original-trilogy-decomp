#include "m2c.h"

extern M2C_UNK data_02118960;

void func_020dae54(void) {
    u8 *p;

    if (M2C_FIELD(&data_02118960, u8 *, 0x24) != 2) {
        return;
    }
    p = M2C_FIELD(&data_02118960, u8 **, 0x1C);
    if (p[0x4B2] == 0) {
        M2C_FIELD(&data_02118960, s8 *, 0x28)  = 9;
        M2C_FIELD(&data_02118960, u8 **, 0x20) = p;
    } else {
        M2C_FIELD(&data_02118960, s8 *, 0x28)  = 4;
        M2C_FIELD(&data_02118960, u8 **, 0x20) = p + 0x220;
    }
    M2C_FIELD(&data_02118960, u8 *, 0x24) = 3;
}
