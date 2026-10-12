#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe048;

void func_020382e8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe048;
}
