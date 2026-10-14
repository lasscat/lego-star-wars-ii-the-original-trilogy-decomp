#include "m2c.h"

M2C_UNK func_0206d4d0(void *, s32, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020fe8c8;
extern s32 data_027e02a4;

void *func_0206d88c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe8c8;
    func_0206d4d0(arg0 + 0x28, data_027e02a4, 1, 2, 3);
    return arg0;
}
