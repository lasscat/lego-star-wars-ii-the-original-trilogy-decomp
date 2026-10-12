#include "m2c.h"

M2C_UNK func_020c4630();                            /* extern */
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0d44;

M2C_UNK *func_020c4688(void) {
    if (!(M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & 0x80)) {
        func_020c4630();
        M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) | 0x80);
    }
    return &data_027e0d44;
}
