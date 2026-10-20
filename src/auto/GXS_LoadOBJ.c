#include "m2c.h"

M2C_UNK MI_DmaCopy32(s32, M2C_UNK, s32, u32);
M2C_UNK MIi_CpuCopy32(M2C_UNK, s32, u32);
extern s32 GXi_DmaId;

/* GXS_GetSubObjCharPtr idiom from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/gx_load2d.c (license:
 * none) */
static inline void *GXS_GetSubObjCharPtr(void) {
    return (void *) 0x6600000;
}

void GXS_LoadOBJ(M2C_UNK arg0, s32 arg1, u32 arg2) {
    u8 *base = (u8 *) GXS_GetSubObjCharPtr();
    if ((GXi_DmaId != -1) && (arg2 > 0x30U)) {
        MI_DmaCopy32(GXi_DmaId, arg0, base + arg1, arg2);
        return;
    }
    MIi_CpuCopy32(arg0, base + arg1, arg2);
}
