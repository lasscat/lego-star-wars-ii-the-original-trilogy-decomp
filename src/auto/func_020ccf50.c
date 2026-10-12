#include "m2c.h"

extern M2C_UNK data_02115424;

s32 func_020ccf50(void) {
    return M2C_FIELD(&data_02115424, s32 *, 0x20) = (s32) (M2C_FIELD(&data_02115424, s32 *, 0x20) + 1);
}
