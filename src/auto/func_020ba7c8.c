#include "m2c.h"

extern M2C_UNK data_0210db84;

s32 func_020ba7c8(void) {
    return M2C_FIELD(&data_0210db84, s32 *, 0x30) - M2C_FIELD(&data_0210db84, s32 *, 0x28);
}
