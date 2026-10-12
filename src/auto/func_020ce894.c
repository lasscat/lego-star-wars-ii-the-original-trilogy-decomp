#include "m2c.h"

M2C_UNK func_020d1134();                            /* extern */
M2C_UNK func_020d1240(M2C_UNK, M2C_UNK *);          /* extern */
s32 func_020d128c(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_0211578c;
extern M2C_UNK func_020ce8e8;

void func_020ce894(void) {
    if (M2C_FIELD(&data_0211578c, u16 *, 2) != 0) {
        return;
    }
    M2C_FIELD(&data_0211578c, u16 *, 2) = 1U;
    func_020d1134();
    do {

    } while (func_020d128c(0xC, 1) == 0);
    func_020d1240(0xC, &func_020ce8e8);
}
