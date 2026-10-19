#include "m2c.h"

M2C_UNK GX_HBlankIntr(M2C_UNK);                     /* extern */
M2C_UNK OS_SetIrqFunction(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK OS_EnableIrqMask(M2C_UNK);                     /* extern */
M2C_UNK OS_EnableInterrupts(M2C_UNK, u16);                /* extern */
extern s32 data_027e038c;
extern s32 data_027e0390;
extern M2C_UNK func_01ffa494;

void func_02060618(void *arg0) {
    u16 temp_r1;

    M2C_FIELD(arg0, s8 *, 0xC34) = 1;
    data_027e0390                = M2C_FIELD(arg0, s32 *, 0xC2C);
    data_027e038c                = M2C_FIELD(arg0, s32 *, 0xC30);
    GX_HBlankIntr(1);
    OS_SetIrqFunction(2, &func_01ffa494);
    OS_EnableIrqMask(2);
    temp_r1             = *(u16 *) 0x04000208;
    *(u16 *) 0x04000208 = 1;
    OS_EnableInterrupts(1, temp_r1);
    *(u16 *) 0x04000004 |= 0x10;
}
