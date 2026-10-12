#include "m2c.h"

M2C_UNK func_020c8510(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0c60;
extern M2C_UNK data_027e0d14;

M2C_UNK *func_020c43a0(void) {
    if (!(M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & 8)) {
        func_020c8510(&data_027e0c60, &data_027e0d14);
        M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) | 8);
    }
    return &data_027e0d14;
}
