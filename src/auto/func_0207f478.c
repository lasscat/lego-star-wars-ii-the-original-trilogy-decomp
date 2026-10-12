#include "m2c.h"

extern M2C_UNK data_020f0030;

s32 func_0207f478(s32 arg0) {
    return *((M2C_UNK *)((s8 *)&data_020f0030 + (arg0 * 4)));
}
