#include "m2c.h"

extern M2C_UNK data_020f88c4;

void func_020ba140(void *arg0) {
    M2C_UNK saved_reg_r10;
    M2C_UNK saved_reg_r11;
    M2C_UNK saved_reg_r5;
    M2C_UNK saved_reg_r6;
    M2C_UNK saved_reg_r7;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r2;
    s32 temp_r3;
    s32 temp_r4;
    s32 var_r10;
    s32 var_r11;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    u8 temp_r1;
    u8 temp_r8;

    var_r5  = saved_reg_r5;
    var_r6  = saved_reg_r6;
    var_r7  = saved_reg_r7;
    var_r10 = saved_reg_r10;
    var_r11 = saved_reg_r11;
    temp_r3 = ((s32) (u16) (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0xF) / (u32) M2C_FIELD(arg0, u32 *, 8)) * 2) >> 4) * 2;
    temp_r8 = M2C_FIELD(arg0, u8 *, 4);
    temp_r4 = *((s16 *) ((s8 *) &data_020f88c4 + ((temp_r3 + 1) * 2))) * 4;
    temp_r0 = (s32) (*((s16 *) ((s8 *) &data_020f88c4 + (temp_r3 * 2))) * 4) / (s32) temp_r8;
    temp_r1 = M2C_FIELD(arg0, u8 *, 0);
    switch (temp_r1) {
        default:
            break;
        case 3:
            var_r7  = 0x4000 - temp_r4;
            var_r6  = var_r7 >> 1;
            sp0     = var_r6;
            var_r5  = temp_r0 + 0x4000;
            var_r11 = 0 - (temp_r4 * 2);
            var_r10 = 0x4000 - temp_r0;
            break;
        case 4:
            temp_r2 = temp_r4 + 0x4000;
            var_r6  = temp_r2 >> 1;
            sp0     = var_r6;
            var_r7  = 0 - temp_r2;
            var_r5  = temp_r0 + 0x4000;
            var_r11 = 0 - (temp_r4 * 2);
            var_r10 = 0x4000 - temp_r0;
            break;
        case 5:
            var_r6  = temp_r8 * temp_r0;
            sp0     = (0 - temp_r8) * temp_r0;
            var_r5  = temp_r0 + 0x4000;
            var_r11 = 0 - (temp_r4 * 2);
            var_r10 = 0x4000 - temp_r0;
            var_r7  = 0;
            break;
        case 6:
            var_r7  = 0 - (temp_r4 * 2);
            var_r6  = 0x4000;
            sp0     = 0x4000;
            var_r11 = var_r7;
            var_r5  = temp_r0 + 0x4000;
            var_r10 = 0x4000 - temp_r0;
            break;
    }
    M2C_FIELD(arg0, s16 *, 0xC)  = (s16) ((s32) (var_r6 << 0xE) / var_r5);
    M2C_FIELD(arg0, s16 *, 0xE)  = (s16) ((s32) (var_r7 << 0xE) / var_r5);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((s32) (sp0 << 0xE) / var_r5);
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((s32) ((0 - var_r11) << 0xE) / var_r5);
    M2C_FIELD(arg0, s16 *, 0x14) = (s16) ((s32) ((0 - var_r10) << 0xE) / var_r5);
}
