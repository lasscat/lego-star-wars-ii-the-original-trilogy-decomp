#include "m2c.h"

M2C_UNK NNS_GfdResetLnkTexVramState();                            /* extern */
extern M2C_UNK *NNS_GfdDefaultFuncAllocTexVram;
extern M2C_UNK *NNS_GfdDefaultFuncFreeTexVram;
extern M2C_UNK mgr_;
extern M2C_UNK NNS_GfdAllocLnkTexVram;
extern M2C_UNK NNS_GfdFreeLnkTexVram;

void NNS_GfdInitLnkTexVramManager(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(&mgr_, s32 *, 0xC)  = arg0;
    M2C_FIELD(&mgr_, s32 *, 0x10) = arg1;
    M2C_FIELD(&mgr_, s32 *, 0x14) = arg2;
    M2C_FIELD(&mgr_, s32 *, 0x18) = arg3;
    NNS_GfdResetLnkTexVramState();
    if (arg4 == 0) {
        return;
    }
    NNS_GfdDefaultFuncAllocTexVram = &NNS_GfdAllocLnkTexVram;
    NNS_GfdDefaultFuncFreeTexVram  = &NNS_GfdFreeLnkTexVram;
}
