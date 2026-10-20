#include "m2c.h"

void MI_DmaCopy32(s32, s32, s32, s32);
void MIi_CpuCopy32(s32, s32, s32);

extern s32 GXi_DmaId;

void GX_LoadOBJ(s32 arg0, s32 arg1, s32 arg2) {
    u32 vram = 0x06400000;
    if ((GXi_DmaId != -1) && ((u32) arg2 > 0x30)) {
        MI_DmaCopy32(GXi_DmaId, arg0, vram + arg1, arg2);
        return;
    }
    MIi_CpuCopy32(arg0, vram + arg1, arg2);
}
