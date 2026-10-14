#include "m2c.h"

extern M2C_UNK data_020ff674;

s32 func_02094024(s32 arg0) {
    return M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_020ff674 + (arg0 * 4))), s32 *, 0x18);
}
