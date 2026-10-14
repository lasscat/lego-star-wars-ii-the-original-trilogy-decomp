#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fde80;

s32 func_02033484(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fde80;
    M2C_FIELD(arg0, s16 *, 0xE)    = 0;
    M2C_FIELD(arg0, s32 *, 0x10)   = 0;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = arg9;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = arg8;
    M2C_FIELD(arg0, s8 *, 0x28)    = 0;
    M2C_FIELD(arg0, s8 *, 0x29)    = (s8) arg2;
    M2C_FIELD(arg0, u8 *, 0x2A)    = (u8) arg3;
    M2C_FIELD(arg0, s8 *, 0x2B)    = (s8) arg4;
    M2C_FIELD(arg0, s8 *, 0x2C)    = (s8) arg5;
    M2C_FIELD(arg0, s8 *, 0x2D)    = (s8) arg6;
    M2C_FIELD(arg0, s8 *, 0x2E)    = (s8) arg7;
    M2C_FIELD(arg0, s8 *, 0x2F)    = 0;
    M2C_FIELD(arg0, u8 *, 0x30)    = (u8) arg3;
    M2C_FIELD(arg0, s8 *, 0x31)    = 1;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    return arg0;
}
