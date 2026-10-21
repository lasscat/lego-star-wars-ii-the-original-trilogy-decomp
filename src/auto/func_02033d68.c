#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fdeec;

void func_02033d68(u8 *a0, s32 a1, s32 *a2, s32 a3, u16 a4, ...) {
    M2C_FIELD(a0, M2C_UNK **, 0x0) = &data_020fdbc4;
    M2C_FIELD(a0, s32 *, 0x4)      = a1;
    M2C_FIELD(a0, u8 *, 0xc)       = 0;
    M2C_FIELD(a0, u8 *, 0xd)       = 0;
    M2C_FIELD(a0, M2C_UNK **, 0x0) = &data_020fdeec;
    M2C_FIELD(a0, s32 *, 0x10)     = a2[0];
    M2C_FIELD(a0, s32 *, 0x14)     = a2[1];
    M2C_FIELD(a0, s32 *, 0x18)     = a2[2];
    M2C_FIELD(a0, s32 *, 0x1c)     = 0;
    M2C_FIELD(a0, s32 *, 0x20)     = 0;
    M2C_FIELD(a0, s32 *, 0x24)     = 0;
    M2C_FIELD(a0, s32 *, 0x28)     = 0;
    M2C_FIELD(a0, s32 *, 0x2c)     = *(s32 *) &a3;
    M2C_FIELD(a0, u16 *, 0x30)     = *(u16 *) &a4;
}
