#include "m2c.h"

M2C_UNK func_020c2ff4(M2C_UNK, u32, void *, u32);   /* extern */

void func_020652f4(s32 arg0, void *arg1) {
    s32 temp_r4;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r5;
    u32 temp_r7;
    u32 temp_r8;

    temp_r3 = M2C_FIELD(arg1, u16 *, 0xC) * 8;
    if (temp_r3 != 0) {
        func_020c2ff4(0, (u32) (M2C_FIELD(arg1, s32 *, 8) << 0x10) >> 0xD, arg1 + M2C_FIELD(arg1, s32 *, 0x14), temp_r3);
        M2C_FIELD(arg1, u16 *, 0x10) = (u16) (M2C_FIELD(arg1, u16 *, 0x10) | 1);
    }
    temp_r5 = M2C_FIELD(arg1, u16 *, 0x1C) * 8;
    if (temp_r5 != 0) {
        temp_r7 = M2C_FIELD(arg1, s32 *, 0x18) << 0x10;
        temp_r8 = temp_r7 >> 0xD;
        temp_r4 = M2C_FIELD(arg1, s32 *, 0x28);
        func_020c2ff4(0, temp_r8, arg1 + M2C_FIELD(arg1, s32 *, 0x24), temp_r5);
        func_020c2ff4(0, ((u32) (0x1FFFF & (temp_r7 >> 0xD)) >> 1) + 0x20000 + ((u32) (temp_r8 & 0x40000) >> 2),
                      arg1 + temp_r4, temp_r5 >> 1);
        M2C_FIELD(arg1, u16 *, 0x20) = (u16) (M2C_FIELD(arg1, u16 *, 0x20) | 1);
    }
    temp_r3_2 = M2C_FIELD(arg1, u16 *, 0x30) * 8;
    if (temp_r3_2 == 0) {
        return;
    }
    func_020c2ff4(1, (u32) (M2C_FIELD(arg1, s32 *, 0x2C) << 0x10) >> 0xD, arg1 + M2C_FIELD(arg1, s32 *, 0x38), temp_r3_2);
    M2C_FIELD(arg1, u16 *, 0x32) = (u16) (M2C_FIELD(arg1, u16 *, 0x32) | 1);
}
