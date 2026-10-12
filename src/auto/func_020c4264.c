#include "m2c.h"

M2C_UNK func_01ffc45c(s32, s32 *, M2C_UNK);         /* extern */
extern M2C_UNK data_027e0c14;
extern s32 data_027e0c18;
extern s32 data_027e0c60;
extern s32 data_027e0c90;

void func_020c4264(void) {
    s32 sp0;

    func_01ffc45c(0x1610, &data_027e0c18, 0x11);
    func_01ffc45c(0x19, &data_027e0c60, 0xC);
    sp0 = 2;
    func_01ffc45c(0x10, &sp0, 1);
    func_01ffc45c(0x15, &data_027e0c90, 0x20);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) ((M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~1) | 2);
}
