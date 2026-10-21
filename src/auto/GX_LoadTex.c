#include "m2c.h"

M2C_UNK MI_DmaCopy32(s32, M2C_UNK, s32, s32);
M2C_UNK MI_DmaCopy32Async(s32, M2C_UNK, s32, s32, s32, s32);
M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, s32);
extern s32 GXi_DmaId;
extern M2C_UNK sClrImg;

void GX_LoadTex(void *arg0, u32 arg1, u32 arg2) {
    u32 second = M2C_FIELD(&sClrImg, u32 *, 0x18);
    u32 dest;
    if (second == 0) {
        dest = M2C_FIELD(&sClrImg, u32 *, 4) + arg1;
    } else if (arg1 + arg2 < M2C_FIELD(&sClrImg, u32 *, 0x1c)) {
        dest = M2C_FIELD(&sClrImg, u32 *, 4) + arg1;
    } else if (arg1 >= M2C_FIELD(&sClrImg, u32 *, 0x1c)) {
        dest = second + arg1 - M2C_FIELD(&sClrImg, u32 *, 0x1c);
    } else {
        u32 n    = M2C_FIELD(&sClrImg, u32 *, 0x1c) - arg1;
        u32 base = M2C_FIELD(&sClrImg, u32 *, 4);
        if (GXi_DmaId != -1 && n > 0x30) {
            MI_DmaCopy32(GXi_DmaId, arg0, base + arg1, n);
        } else {
            MIi_CpuCopy32(arg0, base + arg1, n);
        }
        if (GXi_DmaId != -1) {
            MI_DmaCopy32Async(GXi_DmaId, (u8 *) arg0 + n, second, arg2 - n, 0, 0);
        } else {
            MIi_CpuCopy32((u8 *) arg0 + n, second, arg2 - n);
        }
        return;
    }
    if (GXi_DmaId != -1) {
        MI_DmaCopy32Async(GXi_DmaId, arg0, dest, arg2, 0, 0);
    } else {
        MIi_CpuCopy32(arg0, dest, arg2);
    }
}
