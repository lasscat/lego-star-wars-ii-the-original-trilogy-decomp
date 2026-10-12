#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fde14;

void func_020327ec(void *arg0, s32 arg1, s16 arg2, s8 arg3) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fde14;
    M2C_FIELD(arg0, s16 *, 0x18) = arg2;
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = arg3;
}
