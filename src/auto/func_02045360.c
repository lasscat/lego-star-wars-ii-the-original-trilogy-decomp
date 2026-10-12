#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe2d0;

void func_02045360(void *arg0, s32 arg1, s8 arg2, u8 arg3) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe2d0;
    M2C_FIELD(arg0, s8 *, 0xE) = arg2;
    M2C_FIELD(arg0, s8 *, 0xF) = 0;
    M2C_FIELD(arg0, u8 *, 0x10) = arg3;
    M2C_FIELD(arg0, s8 *, 0x12) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    if ((u32) M2C_FIELD(arg0, u8 *, 0x10) > 1U) {
        M2C_FIELD(arg0, s8 *, 0x11) = 1;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x11) = 0;
}
