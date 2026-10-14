#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe000;

void func_02037394(void *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe000;
    M2C_FIELD(arg0, s16 *, 0xE)    = arg2;
}
