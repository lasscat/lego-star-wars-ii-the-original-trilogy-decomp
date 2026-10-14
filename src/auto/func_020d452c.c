#include "m2c.h"

s32 func_020d44b8(M2C_UNK, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_020d4be8();                            /* extern */
extern M2C_UNK data_021174f4;
extern M2C_UNK func_020d4bd8;

s32 func_020d452c(M2C_UNK arg0) {
    s32 temp_r0;

    temp_r0                                = func_020d44b8(arg0, &func_020d4bd8, 0);
    M2C_FIELD(&data_021174f4, s32 *, 0x24) = temp_r0;
    if (temp_r0 == 0) {
        func_020d4be8();
    }
    return M2C_FIELD(&data_021174f4, s32 *, 0x24);
}
