#include "m2c.h"

s32 func_020c3264(M2C_UNK *, M2C_UNK *, u32, s32);  /* extern */
extern M2C_UNK data_02112644;
extern M2C_UNK data_02112648;

s32 func_020c380c(s32 arg0) {
    if (func_020c3264(&data_02112644, &data_02112648, (u32) (arg0 << 0x10) >> 0xD, ((u32) (arg0 & ~0xFFFF) >> 0x10) * 8) == 0) {
        return 1;
    }
    return 0;
}
