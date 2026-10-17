#include "m2c.h"

extern M2C_UNK data_020f6bc2;

s32 func_020047d4(void *arg0) {
    if ((*((u16 *) ((s8 *) &data_020f6bc2 + (M2C_FIELD(arg0, u8 *, 0x6C3) * 0x24))) & 0x20) == 0x20) {
        return 1;
    }
    return 0;
}
