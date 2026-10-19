#include "m2c.h"
s32 func_020ab6c8(void *);
s32 func_020ab6dc(void *, M2C_UNK);
s32 func_020c2ff4(M2C_UNK, s32, M2C_UNK, M2C_UNK);
M2C_UNK func_020cc54c();
M2C_UNK func_020cc580(M2C_UNK, s32, M2C_UNK);
M2C_UNK func_020cc5ec();
M2C_UNK func_020cdd40(M2C_UNK, M2C_UNK);
s32 func_020ab828(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, u8 arg5) {
    s32 temp_r6;
    s32 temp_r8;
    void *temp_r1;
    void *temp_r2;
    if (M2C_FIELD(arg0, u16 *, 0x14) & 1) {
        temp_r2                         = M2C_FIELD(arg0, void **, 0xC);
        temp_r1                         = M2C_FIELD(arg0, void **, 8);
        M2C_FIELD(temp_r2, s32 *, 8)    = (s32) M2C_FIELD(temp_r1, s32 *, 0);
        M2C_FIELD(temp_r2, s32 *, 0x18) = (s32) M2C_FIELD(temp_r1, s32 *, 4);
        M2C_FIELD(temp_r2, s32 *, 0x2C) = (s32) M2C_FIELD(temp_r1, s32 *, 8);
    }
    temp_r8 = func_020ab6c8(arg0);
    temp_r6 = func_020ab6dc(arg0, arg1);
    temp_r6 += arg4;
    if (arg5 != 0) {
        func_020cdd40(arg2, arg3);
        func_020cc54c();
        func_020cc580(arg2, temp_r8 + temp_r6, arg3);
        func_020cc5ec();
        return 1;
    }
    if (func_020c2ff4(1, temp_r8 + temp_r6, arg2, arg3) != 0) {
        return 1;
    }
    return 0;
}
