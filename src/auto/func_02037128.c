#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fdfdc;

void func_02037128(void *arg0, s32 arg1, void *arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdfdc;
    M2C_FIELD(arg0, u16 *, 0x10)   = (u16) M2C_FIELD(arg2, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0x12)   = (u16) M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(arg0, u8 *, 0x14)    = (u8) M2C_FIELD(arg2, u8 *, 4);
    M2C_FIELD(arg0, u8 *, 0x15)    = (u8) M2C_FIELD(arg2, u8 *, 5);
    M2C_FIELD(arg0, s32 *, 0x18)   = (s32) M2C_FIELD(arg2, s32 *, 8);
    M2C_FIELD(arg0, u8 *, 0x1C)    = (u8) M2C_FIELD(arg2, u8 *, 0xC);
    M2C_FIELD(arg0, u8 *, 0x1D)    = (u8) M2C_FIELD(arg2, u8 *, 0xD);
    M2C_FIELD(arg0, u8 *, 0x1E)    = (u8) M2C_FIELD(arg2, u8 *, 0xE);
    M2C_FIELD(arg0, u8 *, 0x1F)    = (u8) M2C_FIELD(arg2, u8 *, 0xF);
    M2C_FIELD(arg0, u8 *, 0x20)    = (u8) M2C_FIELD(arg2, u8 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x24)   = (s32) M2C_FIELD(arg2, s32 *, 0x14);
}
