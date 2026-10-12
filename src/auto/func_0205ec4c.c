#include "m2c.h"

extern s32 data_027e02a4;

void func_0205ec4c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x48) = arg1;
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x4C) = arg2;
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x50) = arg3;
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x54) = arg4;
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x58) = 0;
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x5C) = 0;
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x60) = 0;
    M2C_FIELD((arg0 + (data_027e02a4 << 5)), s32 *, 0x64) = 0;
}
