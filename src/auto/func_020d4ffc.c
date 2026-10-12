#include "m2c.h"

extern M2C_UNK data_021175a0;

s32 func_020d4ffc(void) {
    if (M2C_FIELD(&data_021175a0, s32 *, 0x114) != 0) {
        return 1;
    }
    return 0;
}
