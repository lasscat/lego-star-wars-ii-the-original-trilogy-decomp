#include "m2c.h"

M2C_UNK MI_DmaCopy32Async(s32, M2C_UNK, s32, s32, s32, s32); /* extern */
M2C_UNK MIi_CpuCopy32(M2C_UNK, s32);                /* extern */
extern s32 GXi_DmaId;

void GXS_LoadBGExtPltt(M2C_UNK arg0, s32 arg1, s32 arg2) {
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, arg0, arg1 + 0x06898000, arg2, 0, 0);
        return;
    }
    MIi_CpuCopy32(arg0, arg1 + 0x06898000);
}
