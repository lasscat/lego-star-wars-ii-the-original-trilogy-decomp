#include "m2c.h"

extern M2C_UNK data_020ed2f5;

s32 func_02046990(void *arg0) {
    if ((((u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0x14E) << 0x1E) >> 0x1F) == 1) &&
        (*((u8 *) ((s8 *) &data_020ed2f5 + (M2C_FIELD(arg0, u8 *, 0x16) * 0x10))) == 0x1F)) {
        return 1;
    }
    return 0;
}
