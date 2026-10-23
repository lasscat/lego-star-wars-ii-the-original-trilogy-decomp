#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fde5c;

void func_02032b44(u8 *a0, s32 a1, s32 *a2, s32 a3, u8 a4, s32 a5, s32 a6, s32 a7, s32 a8, ...) {
    M2C_FIELD(a0, M2C_UNK **, 0x0) = &data_020fdbc4;
    M2C_FIELD(a0, s32 *, 0x4)      = a1;
    M2C_FIELD(a0, u8 *, 0xc)       = 0;
    M2C_FIELD(a0, u8 *, 0xd)       = 0;
    M2C_FIELD(a0, M2C_UNK **, 0x0) = &data_020fde5c;
    M2C_FIELD(a0, s32 *, 0x10)     = a2[0];
    M2C_FIELD(a0, s32 *, 0x14)     = a2[1];
    M2C_FIELD(a0, s32 *, 0x18)     = a2[2];
    M2C_FIELD(a0, s32 *, 0x1c)     = *(s32 *) &a3;
    M2C_FIELD(a0, s32 *, 0x20)     = 0;
    M2C_FIELD(a0, s32 *, 0x24)     = 0;
    M2C_FIELD(a0, s32 *, 0x28)     = 0;
    M2C_FIELD(a0, s32 *, 0x2c)     = a8;
    M2C_FIELD(a0, u16 *, 0x38)     = a5;
    M2C_FIELD(a0, u16 *, 0x3a)     = a6;
    M2C_FIELD(a0, u8 *, 0x3c)      = a7;
    M2C_FIELD(a0, u8 *, 0x3d)      = a4;
}
