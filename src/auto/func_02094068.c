#include "m2c.h"

extern M2C_UNK data_020f69ca;

u8 func_02094068(s32 arg0) {
    return *((u8 *) ((s8 *) &data_020f69ca + (arg0 * 8)));
}
