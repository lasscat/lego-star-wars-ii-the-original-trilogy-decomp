#include "m2c.h"

extern M2C_UNK data_020f69c9;

u8 func_02094058(s32 arg0) {
    return *((u8 *) ((s8 *) &data_020f69c9 + (arg0 * 8)));
}
