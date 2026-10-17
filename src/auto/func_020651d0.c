#include "m2c.h"

M2C_UNK func_020c2ff4(M2C_UNK, u32, s32, s32);      /* extern */
M2C_UNK func_020cc364();                            /* extern */
M2C_UNK func_020cc3c0(s32, u32, s32);               /* extern */
M2C_UNK func_020cc500();                            /* extern */
M2C_UNK func_020cc54c();                            /* extern */
M2C_UNK func_020cc580(s32, u32, s32);               /* extern */
M2C_UNK func_020cc5ec();                            /* extern */
M2C_UNK func_020cdd40(s32, s32);                    /* extern */
extern s32 data_027e02a8;

void func_020651d0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 temp_r1;
    u32 temp_r2;
    u32 temp_r6;
    u32 temp_r9;
    u32 temp_r4;
    u32 temp_r8;

    if (arg3 != 0) {
        data_027e02a8 |= 0x80;
    }
    if (arg1 != 0) {
        temp_r2 = M2C_FIELD(arg0, s32 *, 0);
        temp_r8 = (u32) (temp_r2 << 0x10) >> 0xD;
        temp_r9 = ((u32) (temp_r2 & 0x7FFF0000) >> 0x10) * 0x10;
        if (arg3 != 0) {
            func_020cdd40(arg1, temp_r9);
            func_020cc364();
            func_020cc3c0(arg1, temp_r8, temp_r9);
            func_020cc500();
        } else {
            func_020c2ff4(0, temp_r8, arg1, temp_r9);
        }
    }
    if (arg2 != 0) {
        temp_r1 = M2C_FIELD(arg0, s32 *, 8);
        temp_r4 = (u32) (temp_r1 << 0x10) >> 0xD;
        temp_r6 = ((u32) (temp_r1 & ~0xFFFF) >> 0x10) * 8;
        if (arg3 != 0) {
            func_020cdd40(arg2, temp_r6);
            func_020cc54c();
            func_020cc580(arg2, temp_r4, temp_r6);
            func_020cc5ec();
        } else {
            func_020c2ff4(1, temp_r4, arg2, temp_r6);
        }
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 2);
    data_027e02a8 &= ~0x80;
}
