#include "m2c.h"
s32 func_020ab648(void *);
s32 func_020ab6a0(void *, M2C_UNK);
s32 func_020c2ff4(M2C_UNK, s32, M2C_UNK, M2C_UNK);
M2C_UNK func_020cc364();
M2C_UNK func_020cc3c0(M2C_UNK, s32, M2C_UNK);
M2C_UNK func_020cc500();
M2C_UNK func_020cdd40(M2C_UNK, M2C_UNK);
s32 func_020ab770(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u8 arg4) {
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
    temp_r8 = func_020ab648(arg0);
    temp_r6 = func_020ab6a0(arg0, arg1);
    if (arg4 != 0) {
        func_020cdd40(arg2, arg3);
        func_020cc364();
        func_020cc3c0(arg2, temp_r8 + temp_r6, arg3);
        func_020cc500();
        return 1;
    }
    if (func_020c2ff4(0, temp_r8 + temp_r6, arg2, arg3) != 0) {
        return 1;
    }
    return 0;
}
