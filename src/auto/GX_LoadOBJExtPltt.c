#include "m2c.h"
M2C_UNK MI_DmaCopy32Async(s32, M2C_UNK, s32, s32, s32, s32);
M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, s32);
extern s32 GXi_DmaId;
extern M2C_UNK sSubBGExtPltt;
void GX_LoadOBJExtPltt(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 off = M2C_FIELD(&sSubBGExtPltt, s32 *, 4) + arg1;
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, arg0, off, arg2, 0, 0);
        return;
    }
    MIi_CpuCopy32(arg0, off, arg2);
}