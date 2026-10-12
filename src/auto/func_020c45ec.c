#include "m2c.h"

M2C_UNK func_020c43e4(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0c1c;
extern M2C_UNK data_027e0dd4;

M2C_UNK *func_020c45ec(void) {
    if (!(M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & 0x10)) {
        func_020c43e4(&data_027e0c1c, &data_027e0dd4);
        M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) | 0x10);
    }
    return &data_027e0dd4;
}
