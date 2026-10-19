#include "m2c.h"

M2C_UNK MI_Copy36B(void *, void *);              /* extern */

void *func_020acd10(void *arg0, void *arg1) {
    MI_Copy36B(arg1, arg0);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg1, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg1, s32 *, 0x28);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg1, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg1, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(arg1, s32 *, 0x38);
    M2C_FIELD(arg0, u16 *, 0x3C) = (u16) M2C_FIELD(arg1, u16 *, 0x3C);
    M2C_FIELD(arg0, u16 *, 0x3E) = (u16) M2C_FIELD(arg1, u16 *, 0x3E);
    M2C_FIELD(arg0, u16 *, 0x40) = (u16) M2C_FIELD(arg1, u16 *, 0x40);
    M2C_FIELD(arg0, u16 *, 0x42) = (u16) M2C_FIELD(arg1, u16 *, 0x42);
    M2C_FIELD(arg0, u8 *, 0x44)  = (u8) M2C_FIELD(arg1, u8 *, 0x44);
    M2C_FIELD(arg0, u8 *, 0x45)  = (u8) M2C_FIELD(arg1, u8 *, 0x45);
    return arg0;
}
