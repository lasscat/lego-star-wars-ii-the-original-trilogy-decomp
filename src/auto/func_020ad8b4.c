#include "m2c.h"

extern M2C_UNK data_0210b320;

void func_020ad8b4(s32 arg0) {
    if (M2C_FIELD(&data_0210b320, s32 *, 0x20) != 9) {
        M2C_FIELD(&data_0210b320, s32 *, 0x30) = arg0;
    }
}
