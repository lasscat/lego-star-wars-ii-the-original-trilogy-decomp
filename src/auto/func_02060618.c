#include "m2c.h"

M2C_UNK func_020c9848(M2C_UNK);                     /* extern */
M2C_UNK func_020cc9c0(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_020ccb04(M2C_UNK);                     /* extern */
M2C_UNK func_020ce7f0(M2C_UNK, u16);                /* extern */
extern s32 data_027e038c;
extern s32 data_027e0390;
extern M2C_UNK func_01ffa494;

void func_02060618(void *arg0) {
    u16 temp_r1;

    M2C_FIELD(arg0, s8 *, 0xC34) = 1;
    data_027e0390 = M2C_FIELD(arg0, s32 *, 0xC2C);
    data_027e038c = M2C_FIELD(arg0, s32 *, 0xC30);
    func_020c9848(1);
    func_020cc9c0(2, &func_01ffa494);
    func_020ccb04(2);
    temp_r1 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = 1;
    func_020ce7f0(1, temp_r1);
    *(u16 *)0x04000004 |= 0x10;
}
