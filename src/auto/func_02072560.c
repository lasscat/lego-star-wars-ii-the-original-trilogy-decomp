#include "m2c.h"

s32 func_0205e540(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020feb50;

void *func_02072560(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s32 *, 8)      = arg2;
    M2C_FIELD(arg0, s32 *, 0xC)    = arg3;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg4;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020feb50;
    M2C_FIELD(arg0, s8 *, 0x30)    = 0;
    temp_r0                        = func_0205e540(0xE0, 3, 4);
    M2C_FIELD(arg0, s32 *, 0x28)   = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x2C)   = (s32) ((temp_r0 + 0x1F) & ~0x1F);
    return arg0;
}
