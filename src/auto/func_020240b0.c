#include "m2c.h"

M2C_UNK func_02011384();                            /* extern */
extern M2C_UNK data_020fd948;
extern M2C_UNK func_02024394;

void *func_020240b0(void *arg0, s32 arg1) {
    func_02011384();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd948;
    M2C_FIELD(arg0, s32 *, 0x21C) = 0;
    M2C_FIELD(arg0, s32 *, 0x220) = 0;
    M2C_FIELD(arg0, s8 *, 0x225) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x10) = &func_02024394;
    if (arg1 == 0x188) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~1);
    }
    return arg0;
}
