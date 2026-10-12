#include "m2c.h"

M2C_UNK func_020d1134();                            /* extern */
M2C_UNK func_020d1240(M2C_UNK, M2C_UNK *);          /* extern */
s32 func_020d128c(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_02117450;
extern M2C_UNK func_020d3030;

void func_020d32b0(void) {
    if (M2C_FIELD(&data_02117450, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_02117450, u16 *, 0) = 1U;
    func_020d1134();
    M2C_FIELD(&data_02117450, s16 *, 0x10) = 0;
    M2C_FIELD(&data_02117450, s32 *, 4) = 0;
    M2C_FIELD(&data_02117450, s32 *, 0x14) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x36) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x34) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x3A) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x38) = 0;
    do {

    } while (func_020d128c(6, 1) == 0);
    func_020d1240(6, &func_020d3030);
}
