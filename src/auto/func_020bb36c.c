#include "m2c.h"

extern M2C_UNK data_0210dc58;

s32 func_020bb36c(s32 arg0) {
    return arg0 | (*((M2C_UNK *) ((s8 *) &data_0210dc58 + (arg0 * 0x1C))) << 8);
}
