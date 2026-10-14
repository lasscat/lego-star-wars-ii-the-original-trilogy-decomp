#include "m2c.h"

void func_020accac(void *arg0, void *arg1, void *arg2, void *arg3) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg3, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg3, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(arg3, s32 *, 8);
    M2C_FIELD(arg0, u16 *, 0x3C) = (u16) M2C_FIELD(arg2, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0x3E) = (u16) M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 0x40) = (u16) M2C_FIELD(arg2, u16 *, 4);
    M2C_FIELD(arg0, u16 *, 0x42) = (u16) M2C_FIELD(arg2, u16 *, 6);
    M2C_FIELD(arg0, s8 *, 0x44)  = 1;
    M2C_FIELD(arg0, s8 *, 0x45)  = 1;
}
