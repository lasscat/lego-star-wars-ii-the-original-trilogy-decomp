#include "m2c.h"

extern M2C_UNK data_020feb88;

s32 func_0207300c(void) {
    if ((M2C_FIELD(&data_020feb88, s32 *, 0) != -1) && (M2C_FIELD(&data_020feb88, s32 *, 4) != -1)) {
        return 1;
    }
    return 0;
}
