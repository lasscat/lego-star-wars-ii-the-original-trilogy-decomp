#include "m2c.h"

extern M2C_UNK data_02117450;

s32 func_020d39f4(s32 arg0) {
    return M2C_FIELD(&data_02117450, u16 *, 0x38) & arg0;
}
