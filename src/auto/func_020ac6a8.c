#include "m2c.h"

M2C_UNK func_01ffc3d8(void);                            /* extern */
M2C_UNK func_01ffc45c(M2C_UNK, s32 *, M2C_UNK);     /* extern */
s32 func_020ace3c(M2C_UNK);                         /* extern */
s32 func_020acf58(M2C_UNK);                         /* extern */
M2C_UNK func_020c4234(void);                            /* extern */
M2C_UNK func_020c42dc(M2C_UNK *);                   /* extern */
M2C_UNK func_020c4304(s32 *);                       /* extern */
M2C_UNK func_020c8144(M2C_UNK *);                   /* extern */
M2C_UNK func_020c8b9c(s32, M2C_UNK *);              /* extern */
M2C_UNK func_020cf318(s32, M2C_UNK *);              /* extern */
extern M2C_UNK data_020ff9b4;
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0c1c;
extern M2C_UNK data_027e0c60;
extern M2C_UNK data_027e0cd0;

u32 func_020ac6a8(void *arg0, M2C_UNK arg1) {
    s32 sp4;
    s32 sp0;
    s32 vec[3];
    u16 temp_r0;
    u32 temp_r0_2;

    temp_r0_2 = (u32) (M2C_FIELD(arg0, u16 *, 0x52) << 0x1C) >> 0x1F;
    if (temp_r0_2 != 0) {
        return temp_r0_2;
    }
    func_020c8144(&data_027e0cd0);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~0xA4);
    func_020c42dc(&data_020ff9b4);
    vec[0] = 0x1000;
    vec[1] = 0x1000;
    vec[2] = 0x1000;
    func_020c4304(vec);
    sp4 = 3;
    func_01ffc45c(0x10, &sp4, 1);
    func_01ffc45c(0x15, NULL, 0);
    sp0 = 2;
    func_01ffc45c(0x10, &sp0, 1);
    func_020cf318(func_020acf58(arg1), &data_027e0c1c);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~0x50);
    func_020c8b9c(func_020ace3c(arg1), &data_027e0c60);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~0xE8);
    func_020c4234();
    func_01ffc3d8();
    M2C_FIELD(arg0, s16 *, 0x56) = 0;
    temp_r0                      = M2C_FIELD(arg0, u16 *, 0x52) | 8;
    M2C_FIELD(arg0, u16 *, 0x52) = temp_r0;
    return (u32) temp_r0;
}
