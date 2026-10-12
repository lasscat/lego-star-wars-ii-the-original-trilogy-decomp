#include "m2c.h"

extern M2C_UNK data_020fdc50;

void func_0202cb90(void *arg0, s32 arg1, s8 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdc50;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s8 *, 8) = arg2;
    M2C_FIELD(arg0, s8 *, 9) = 0;
    M2C_FIELD(arg0, s8 *, 0xA) = 1;
}
