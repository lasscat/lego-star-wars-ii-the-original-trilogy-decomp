#include "m2c.h"

extern M2C_UNK data_02108d84;

void func_02085e74(s32 arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(&data_02108d84, s8 *, 0x569) = arg1;
    M2C_FIELD(&data_02108d84, s8 *, 0x56A) = arg2;
}
