#include "m2c.h"

extern M2C_UNK data_020ff674;

s32 func_02093fe4(s32 arg0, s32 arg1) {
    return M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_020ff674 + (arg0 * 4))), s32 *, 0x14) + (arg1 * 8);
}
