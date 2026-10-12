#include "m2c.h"

extern M2C_UNK data_0210b320;

s32 func_020aecd8(void) {
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x26;
    if (M2C_FIELD(&data_0210b320, s32 *, 0x20) == 6) {
        return 1;
    }
    return 0;
}
