#include "m2c.h"
s32 func_020ab648(void *);
s32 func_020ab6a0(void *, M2C_UNK);
s32 NNS_GfdRegisterNewVramTransferTask(M2C_UNK, s32, M2C_UNK, M2C_UNK);
M2C_UNK GX_BeginLoadTex();
M2C_UNK GX_LoadTex(M2C_UNK, s32, M2C_UNK);
M2C_UNK GX_EndLoadTex();
M2C_UNK DC_FlushRange(M2C_UNK, M2C_UNK);
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
        DC_FlushRange(arg2, arg3);
        GX_BeginLoadTex();
        GX_LoadTex(arg2, temp_r8 + temp_r6, arg3);
        GX_EndLoadTex();
        return 1;
    }
    if (NNS_GfdRegisterNewVramTransferTask(0, temp_r8 + temp_r6, arg2, arg3) != 0) {
        return 1;
    }
    return 0;
}
