#include "m2c.h"

extern M2C_UNK data_02101b7c;

s32 func_02053940(void *arg0) {
    if (*((M2C_UNK *) ((s8 *) &data_02101b7c + (M2C_FIELD(arg0, s32 *, 0) << 5))) & (0x100 << M2C_FIELD(arg0, s32 *, 4))) {
        return 1;
    }
    return 0;
}
