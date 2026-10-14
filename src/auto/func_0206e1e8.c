#include "m2c.h"

M2C_UNK func_020536a8(s32, M2C_UNK);                /* extern */
M2C_UNK func_0206e2a0(void *);                      /* extern */
s8 func_02086f20(M2C_UNK *, s32);                   /* extern */
extern M2C_UNK data_020fe77c;
extern M2C_UNK data_020fe938;
extern M2C_UNK data_02104d90;

void *func_0206e1e8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe77c;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s16 *, 8)      = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe938;
    M2C_FIELD(arg0, s32 *, 0xC)    = arg3;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg2;
    M2C_FIELD(arg0, s32 *, 0x14)   = arg4;
    M2C_FIELD(arg0, s32 *, 0x18)   = arg5;
    M2C_FIELD(arg0, s32 *, 0x1C)   = arg6;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0x8C;
    M2C_FIELD(arg0, s8 *, 0x25)    = 0;
    M2C_FIELD(arg0, s8 *, 0x29)    = (s8) arg7;
    M2C_FIELD(arg0, s8 *, 0x2A)    = (s8) arg8;
    M2C_FIELD(arg0, s8 *, 0x28)    = 3;
    M2C_FIELD(arg0, s8 *, 0x24)    = func_02086f20(&data_02104d90, M2C_FIELD(arg0, s32 *, 0x14));
    func_0206e2a0(arg0);
    func_020536a8(M2C_FIELD(arg0, s32 *, 0x10), 1);
    return arg0;
}
