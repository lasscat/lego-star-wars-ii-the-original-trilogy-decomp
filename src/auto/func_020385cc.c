#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe090;

void func_020385cc(void *arg0, void *arg1, s32 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, void **, 4)    = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe090;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg2;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s8 *, 0x19)    = 0;
    M2C_FIELD(arg0, s8 *, 0x18)    = (s8) M2C_FIELD(arg1, s16 *, 0x6B6);
}
