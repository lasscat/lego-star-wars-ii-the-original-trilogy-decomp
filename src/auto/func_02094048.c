#include "m2c.h"

extern M2C_UNK data_020f69c8;

u8 func_02094048(s32 arg0) {
    return *((u8 *) ((s8 *) &data_020f69c8 + (arg0 * 8)));
}
