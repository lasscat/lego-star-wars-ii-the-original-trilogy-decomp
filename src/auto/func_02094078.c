#include "m2c.h"

extern M2C_UNK data_020f69cb;

u8 func_02094078(s32 arg0) {
    return *((u8 *) ((s8 *) &data_020f69cb + (arg0 * 8)));
}
