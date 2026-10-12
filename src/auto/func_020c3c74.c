#include "m2c.h"

M2C_UNK func_020cc364();                            /* extern */
M2C_UNK func_020cc3c0(void *, u32, u32);            /* extern */
M2C_UNK func_020cc500();                            /* extern */

void func_020c3c74(void *arg0, s32 arg1) {
    s32 temp_r5;
    u32 temp_r2;
    u32 temp_r4;
    u32 temp_r6;
    u32 temp_r7;

    if (arg1 != 0) {
        func_020cc364();
    }
    temp_r2 = M2C_FIELD(arg0, u16 *, 0xC) * 8;
    if (temp_r2 != 0) {
        func_020cc3c0(arg0 + M2C_FIELD(arg0, s32 *, 0x14), (u32) (M2C_FIELD(arg0, s32 *, 8) << 0x10) >> 0xD, temp_r2);
        M2C_FIELD(arg0, u16 *, 0x10) = (u16) (M2C_FIELD(arg0, u16 *, 0x10) | 1);
    }
    temp_r6 = M2C_FIELD(arg0, u16 *, 0x1C) * 8;
    if (temp_r6 != 0) {
        temp_r4 = M2C_FIELD(arg0, s32 *, 0x18) << 0x10;
        temp_r7 = temp_r4 >> 0xD;
        temp_r5 = M2C_FIELD(arg0, s32 *, 0x28);
        func_020cc3c0(arg0 + M2C_FIELD(arg0, s32 *, 0x24), temp_r7, temp_r6);
        func_020cc3c0(arg0 + temp_r5, ((u32) (0x1FFFF & (temp_r4 >> 0xD)) >> 1) + 0x20000 + ((u32) (temp_r7 & 0x40000) >> 2), temp_r6 >> 1);
        M2C_FIELD(arg0, u16 *, 0x20) = (u16) (M2C_FIELD(arg0, u16 *, 0x20) | 1);
    }
    if (arg1 == 0) {
        return;
    }
    func_020cc500();
}
