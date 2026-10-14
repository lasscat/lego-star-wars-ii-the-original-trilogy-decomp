#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fdfb8;

void func_02036dfc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdfb8;
}
