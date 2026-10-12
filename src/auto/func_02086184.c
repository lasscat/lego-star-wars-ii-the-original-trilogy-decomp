#include "m2c.h"

extern M2C_UNK data_02104364;

void func_02086184(void *arg0, s8 arg1) {
    M2C_FIELD(&data_02104364, s8 *, 0x4E) = arg1;
    M2C_FIELD(arg0, s8 *, 0x443C) = 1;
}
