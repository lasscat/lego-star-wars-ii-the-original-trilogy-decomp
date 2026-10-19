#include "m2c.h"

M2C_UNK MIi_CpuClear32(M2C_UNK, void *, M2C_UNK);    /* extern */
extern s32 NNS_G3dFuncBlendVisDefault;
extern s32 NNS_G3dFuncBlendJntDefault;
extern s32 NNS_G3dFuncBlendMatDefault;

void NNS_G3dRenderObjInit(void *arg0, s32 arg1) {
    MIi_CpuClear32(0, arg0, 0x54);
    M2C_FIELD(arg0, s32 *, 0xC)  = (s32) NNS_G3dFuncBlendMatDefault;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) NNS_G3dFuncBlendJntDefault;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) NNS_G3dFuncBlendVisDefault;
    M2C_FIELD(arg0, s32 *, 4)    = arg1;
}
