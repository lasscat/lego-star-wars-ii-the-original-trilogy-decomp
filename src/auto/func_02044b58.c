#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe288;

void func_02044b58(void *arg0, s32 arg1, void *arg2, s8 arg3, s32 arg4) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe288;
    M2C_FIELD(arg0, s32 *, 0x18)   = (s32) M2C_FIELD(arg2, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x1C)   = (s32) M2C_FIELD(arg2, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x20)   = (s32) M2C_FIELD(arg2, s32 *, 8);
    M2C_FIELD(arg0, s8 *, 0x24)    = arg3;
    M2C_FIELD(arg0, s8 *, 0x25)    = (s8) arg4;
}
