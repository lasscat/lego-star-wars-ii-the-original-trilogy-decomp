#include "m2c.h"

extern M2C_UNK data_020ff674;

u8 func_02093f94(s32 arg0) {
    return M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_020ff674 + (arg0 * 4))), u8 *, 4);
}
