#include "m2c.h"

s32 func_020c43a0();                                /* extern */
s32 func_020c45ec();                                /* extern */
M2C_UNK func_020c84a8(s32, M2C_UNK *);              /* extern */
M2C_UNK func_020c8c04(s32, M2C_UNK *, M2C_UNK *);   /* extern */
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0e14;

M2C_UNK *func_020c46f8(void) {
    u8 sp0[64];
    s32 temp_r4;
    s32 temp_r5;

    if (!(M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & 0x40)) {
        temp_r5 = func_020c43a0();
        temp_r4 = func_020c45ec();
        func_020c84a8(temp_r5, sp0);
        func_020c8c04(temp_r4, sp0, &data_027e0e14);
        M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) | 0x40);
    }
    return &data_027e0e14;
}
