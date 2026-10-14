#include "m2c.h"

M2C_UNK func_020cafe0(M2C_UNK, M2C_UNK, u16, u16);  /* extern */
extern M2C_UNK data_027e0874;

void func_02059a24(s32 arg0, void *arg1) {
    u16 temp_r3;

    M2C_FIELD(&data_027e0874, u16 *, 0x44) = (u16) M2C_FIELD(arg1, u8 *, 5);
    M2C_FIELD(&data_027e0874, s16 *, 0x46) = (s16) M2C_FIELD(arg1, s16 *, 2);
    if (M2C_FIELD(arg1, u8 *, 4) == 1) {
        M2C_FIELD(&data_027e0874, s8 *, 0x40) = 1;
        func_020cafe0(1, 0, M2C_FIELD(&data_027e0874, u16 *, 0x44), (u16) M2C_FIELD(&data_027e0874, s16 *, 0x46));
    } else {
        M2C_FIELD(&data_027e0874, s8 *, 0x40) = 0;
        func_020cafe0(0, 0, M2C_FIELD(&data_027e0874, u16 *, 0x44), (u16) M2C_FIELD(&data_027e0874, s16 *, 0x46));
    }
    temp_r3                                = M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(&data_027e0874, u16 *, 0x42) = (u16) ((temp_r3 & 0x1F) | ((u32) (((s32) temp_r3 >> 5) << 0x1B) >> 0x16) |
                                                    ((u32) (((s32) temp_r3 >> 0xA) << 0x1B) >> 0x11));
    *(s32 *) 0x04000358                    = M2C_FIELD(&data_027e0874, u16 *, 0x42) | 0x1F0000;
}
