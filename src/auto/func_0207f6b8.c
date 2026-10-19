#include "m2c.h"
void func_0207f890(void *arg0);
void func_0207f6b8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6, u8 arg7, s32 arg8, s32 arg9) {
    M2C_FIELD(arg0, s32 *, 4)    = arg1;
    M2C_FIELD(arg0, s32 *, 8)    = arg2;
    M2C_FIELD(arg0, s32 *, 0xC)  = arg3;
    M2C_FIELD(arg0, s32 *, 0x14) = arg4;
    M2C_FIELD(arg0, s32 *, 0x10) = arg5;
    M2C_FIELD(arg0, u8 *, 0x22)  = arg6;
    M2C_FIELD(arg0, u8 *, 0x23)  = arg7;
    M2C_FIELD(arg0, s32 *, 0x18) = arg8;
    M2C_FIELD(arg0, s32 *, 0x1C) = arg9;
    if (M2C_FIELD(arg0, s32 *, 8) == -1) {
        M2C_FIELD(arg0, s8 *, 0x24) = 1;
    }
    func_0207f890(arg0);
}
