#include "m2c.h"

s32 func_02017800(s32);                             /* extern */
s32 func_02017820(s32, s32);                        /* extern */
extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe0b4;

void *func_02038af0(void *arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 temp_r0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe0b4;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg2;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, s32 *, 0x28)   = 0;
    M2C_FIELD(arg0, s32 *, 0x2C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x30)   = 0;
    M2C_FIELD(arg0, s32 *, 0x34)   = 0;
    M2C_FIELD(arg0, s32 *, 0x38)   = 0;
    M2C_FIELD(arg0, s32 *, 0x3C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x40)   = 0;
    M2C_FIELD(arg0, s32 *, 0x44)   = 0;
    M2C_FIELD(arg0, s32 *, 0x48)   = 0;
    M2C_FIELD(arg0, s32 *, 0x4C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x50)   = 0;
    M2C_FIELD(arg0, s32 *, 0x54)   = 0;
    M2C_FIELD(arg0, s32 *, 0x58)   = 0;
    M2C_FIELD(arg0, s32 *, 0x5C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x64)   = 0;
    M2C_FIELD(arg0, s32 *, 0x68)   = 0;
    M2C_FIELD(arg0, s8 *, 0x6C)    = arg3;
    temp_r0                        = func_02017800(M2C_FIELD(arg0, s32 *, 0x10));
    M2C_FIELD(arg0, s32 *, 0x14)   = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x18)   = func_02017820(temp_r0, M2C_FIELD(arg0, s32 *, 0x10));
    return arg0;
}
