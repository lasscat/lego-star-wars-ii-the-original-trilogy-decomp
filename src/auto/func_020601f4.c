#include "m2c.h"

extern M2C_UNK data_021029e0;

void func_020601f4(s32 arg0, s32 arg1, s32 arg2) {
    *((M2C_UNK *)((s8 *)&data_021029e0 + (arg2 << 5))) = arg1;
}
