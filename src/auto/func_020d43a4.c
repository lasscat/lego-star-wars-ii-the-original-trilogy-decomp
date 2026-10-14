#include "m2c.h"

M2C_UNK func_020d1134();                            /* extern */
M2C_UNK func_020d1240(M2C_UNK, M2C_UNK *);          /* extern */
s32 func_020d128c(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_021174f4;
extern M2C_UNK func_020d4618;

void func_020d43a4(void) {
    if (M2C_FIELD(&data_021174f4, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_021174f4, u16 *, 0)    = 1U;
    M2C_FIELD(&data_021174f4, s32 *, 4)    = 0;
    M2C_FIELD(&data_021174f4, s32 *, 8)    = 0;
    M2C_FIELD(&data_021174f4, s32 *, 0x20) = 0;
    M2C_FIELD(&data_021174f4, s32 *, 0xC)  = 0;
    M2C_FIELD(&data_021174f4, s32 *, 0x10) = 0;
    func_020d1134();
    do {

    } while (func_020d128c(5, 1) == 0);
    func_020d1240(5, &func_020d4618);
}
