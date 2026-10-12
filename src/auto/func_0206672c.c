#include "m2c.h"

extern M2C_UNK data_02104914;

s8 *func_0206672c(s32 arg0, s8 *arg1) {
    s32 var_r0;
    s32 var_r2;
    s8 *var_r3;

    var_r0 = arg0;
    var_r3 = arg1;
    var_r2 = -1;
    if (var_r0 < 0) {
        *arg1 = 0x2D;
        var_r0 = 0 - var_r0;
        var_r3 += 1;
    }
    if (var_r0 >= 0x3B9ACA00) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0x3B9ACA00;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(s32 *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(s32 *)0x040002A0;
        M2C_FIELD(var_r3, volatile s8 *, 0) = var_r2 + 0x30;
        M2C_FIELD(var_r3, volatile u8 *, 1) = (u8) M2C_FIELD(&data_02104914, volatile u8 *, 1);
        var_r3 += 2;
    }
    if ((var_r0 >= 0x05F5E100) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0x05F5E100;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(M2C_UNK *)0x040002A0;
        *var_r3 = var_r2 + 0x30;
        var_r3 += 1;
    }
    if ((var_r0 >= 0x989680) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0x989680;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(M2C_UNK *)0x040002A0;
        *var_r3 = var_r2 + 0x30;
        var_r3 += 1;
    }
    if ((var_r0 >= 0xF4240) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0xF4240;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(M2C_UNK *)0x040002A0;
        M2C_FIELD(var_r3, volatile s8 *, 0) = var_r2 + 0x30;
        M2C_FIELD(var_r3, volatile u8 *, 1) = (u8) M2C_FIELD(&data_02104914, volatile u8 *, 1);
        var_r3 += 2;
    }
    if ((var_r0 >= 0x186A0) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0x186A0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(M2C_UNK *)0x040002A0;
        *var_r3 = var_r2 + 0x30;
        var_r3 += 1;
    }
    if ((var_r0 >= 0x2710) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0x2710;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(M2C_UNK *)0x040002A0;
        *var_r3 = var_r2 + 0x30;
        var_r3 += 1;
    }
    if ((var_r0 >= 0x3E8) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0x3E8;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(M2C_UNK *)0x040002A0;
        M2C_FIELD(var_r3, volatile s8 *, 0) = var_r2 + 0x30;
        M2C_FIELD(var_r3, volatile u8 *, 1) = (u8) M2C_FIELD(&data_02104914, volatile u8 *, 1);
        var_r3 += 2;
    }
    if ((var_r0 >= 0x64) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0x64;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r2 = *(M2C_UNK *)0x040002A0;
        *var_r3 = var_r2 + 0x30;
        var_r3 += 1;
    }
    if ((var_r0 >= 0xA) || (var_r2 != -1)) {
        M2C_FIELD((void *)0x04000280, volatile u16 *, 0) = 0U;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x10) = var_r0;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x18) = 0xA;
        M2C_FIELD((void *)0x04000280, volatile s32 *, 0x1C) = 0;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        var_r0 = *(M2C_UNK *)0x040002A8;
        do {

        } while (M2C_FIELD((void *)0x04000280, volatile u16 *, 0) & 0x8000);
        *var_r3 = *(M2C_UNK *)0x040002A0 + 0x30;
        var_r3 += 1;
    }
    M2C_FIELD(var_r3, volatile s8 *, 0) = var_r0 + 0x30;
    M2C_FIELD(var_r3, volatile s8 *, 1) = 0;
    return arg1;
}
