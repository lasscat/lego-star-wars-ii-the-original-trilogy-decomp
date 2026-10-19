#include "m2c.h"

M2C_UNK func_01ffc45c(M2C_UNK, s32 *, M2C_UNK);     /* extern */
M2C_UNK func_020c4234();                            /* extern */
M2C_UNK func_020c42dc(M2C_UNK *);                   /* extern */
M2C_UNK func_020c4304(s32 *);                       /* extern */
M2C_UNK func_020c8144(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020ff9b4;
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0cd0;

void func_02095854(void) {
    s32 sp10[3];
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 sp0;

    spC = 3;
    func_01ffc45c(0x10, &spC, 1);
    func_01ffc45c(0x15, NULL, 0);
    sp8 = 2;
    func_01ffc45c(0x10, &sp8, 1);
    func_020c8144(&data_027e0cd0);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~0xA4);
    func_020c42dc(&data_020ff9b4);
    sp10[0] = 0x1000;
    sp10[1] = 0x1000;
    sp10[2] = 0x1000;
    func_020c4304(sp10);
    func_020c4234();
    sp4 = 0x7FFFFFFF;
    func_01ffc45c(0x30, &sp4, 1);
    sp0 = 0xFFFF;
    func_01ffc45c(0x31, &sp0, 1);
}
