#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0206549c(void *);                      /* extern */
s32 func_0206d4d0(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020fe7fc;
extern s32 data_020ff9a4;

void *func_02069db8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_r0;
    s32 var_r0_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    M2C_FIELD(arg0, s32 *, 0xC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x10) = arg4;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe7fc;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) data_020ff9a4;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_020534e0(arg0 + 0x38);
    func_020534e0(arg0 + 0x40);
    func_020534e0(arg0 + 0x48);
    func_0206549c(arg0 + 0x50);
    M2C_FIELD(arg0, s8 *, 0x80) = 0;
    M2C_FIELD(arg0, s8 *, 0x81) = 0;
    M2C_FIELD(arg0, s16 *, 0x84) = 0;
    M2C_FIELD(arg0, s16 *, 0x86) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    var_r0 = func_0205e80c(0x2C, 3, 4);
    if (var_r0 != 0) {
        var_r0 = func_0206d4d0(var_r0, 0, 1, 2, 3);
    }
    M2C_FIELD(arg0, s32 *, 0x88) = var_r0;
    var_r0_2 = func_0205e80c(0x2C, 3, 4);
    if (var_r0_2 != 0) {
        var_r0_2 = func_0206d4d0(var_r0_2, 1, 1, 0, 1);
    }
    M2C_FIELD(arg0, s32 *, 0x8C) = var_r0_2;
    return arg0;
}
