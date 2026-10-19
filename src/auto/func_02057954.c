#include "m2c.h"

void *func_020aaeb4();                              /* extern */

void func_02057954(s32 arg0, void *arg1) {
    volatile s32 sp1C;
    volatile s32 sp18;
    volatile s32 sp14;
    volatile s32 sp10;
    volatile s32 spC;
    volatile s32 sp8;
    volatile s32 sp4;
    volatile s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s8 var_r4;
    u8 temp_r5;
    u8 temp_r5_2;

    temp_r5                                  = M2C_FIELD(arg1, u8 *, 8);
    M2C_FIELD(func_020aaeb4(), u8 *, 0x290)  = temp_r5;
    temp_r0                                  = M2C_FIELD(arg1, u16 *, 2) << 0xC;
    spC                                      = temp_r0;
    sp1C                                     = temp_r0;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x284) = spC;
    temp_r0_2                                = M2C_FIELD(arg1, u16 *, 0) << 0xC;
    sp8                                      = temp_r0_2;
    sp18                                     = temp_r0_2;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x280) = sp8;
    temp_r0_3                                = M2C_FIELD(arg1, u16 *, 6) << 0xC;
    sp4                                      = temp_r0_3;
    sp14                                     = temp_r0_3;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x28C) = sp4;
    temp_r0_4                                = M2C_FIELD(arg1, u16 *, 4) << 0xC;
    sp0                                      = temp_r0_4;
    sp10                                     = temp_r0_4;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x288) = sp0;
    temp_r5_2                                = M2C_FIELD(arg1, u8 *, 9);
    M2C_FIELD(func_020aaeb4(), u8 *, 0x291)  = temp_r5_2;
    if (M2C_FIELD(arg1, u8 *, 0xA) != 0) {
        var_r4 = 1;
    } else {
        var_r4 = 0;
    }
    M2C_FIELD(func_020aaeb4(), s8 *, 0x292) = var_r4;
}
