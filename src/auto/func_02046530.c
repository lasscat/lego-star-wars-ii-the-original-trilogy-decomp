#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe318;

void func_02046530(void *arg0, s32 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe318;
    M2C_FIELD(arg0, s8 *, 0xE) = arg2;
    M2C_FIELD(arg0, s8 *, 0x16) = 0x1F;
    M2C_FIELD(arg0, s8 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = arg3;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
}
