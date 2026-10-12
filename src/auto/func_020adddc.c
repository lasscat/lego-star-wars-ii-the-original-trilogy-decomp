#include "m2c.h"

extern M2C_UNK data_0210b320;

void func_020adddc(s32 arg0, s32 arg1) {
    if (arg1 > 0) {
        M2C_FIELD(&data_0210b320, s32 *, 0x14) = arg1;
    }
}
