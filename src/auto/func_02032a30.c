#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fde38;

void func_02032a30(void *arg0, s32 arg1, s32 arg2, s16 arg3, u16 arg4, u8 arg5) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fde38;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg2;
    M2C_FIELD(arg0, u16 *, 0x14)   = arg4;
    M2C_FIELD(arg0, s16 *, 0x16)   = arg3;
    M2C_FIELD(arg0, u8 *, 0x18)    = arg5;
}
