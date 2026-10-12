#include "m2c.h"

M2C_UNK func_020ad8b4();                            /* extern */
s32 func_020d7390(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020ae1d0;

s32 func_020ae170(void) {
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x28;
    if ((u32) (M2C_FIELD(&data_0210b320, s32 *, 0x20) - 4) <= 2U) {
        return 1;
    }
    if (func_020d7390(&func_020ae1d0) != 2) {
        func_020ad8b4();
        return 0;
    }
    M2C_FIELD(&data_0210b320, s16 *, 8) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0xE) = 1;
    return 1;
}
