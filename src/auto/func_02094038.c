#include "m2c.h"

extern M2C_UNK data_020f69c4;

s32 func_02094038(s32 arg0) {
    return *((M2C_UNK *) ((s8 *) &data_020f69c4 + (arg0 * 8)));
}
