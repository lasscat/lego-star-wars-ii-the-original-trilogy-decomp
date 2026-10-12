#include "m2c.h"

extern M2C_UNK data_0211e400;

s32 func_020dce58(void) {
    if (M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), u8 *, 0x50D) == 1) {
        return 1;
    }
    return 0;
}
