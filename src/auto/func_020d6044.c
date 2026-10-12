#include "m2c.h"

M2C_UNK func_020d1134();                            /* extern */
M2C_UNK func_020d1240(M2C_UNK, M2C_UNK *);          /* extern */
extern M2C_UNK data_02117e00;
extern M2C_UNK func_020d6070;

void func_020d6044(void) {
    func_020d1134();
    func_020d1240(0xE, &func_020d6070);
    M2C_FIELD(&data_02117e00, s32 *, 4) = 0;
}
