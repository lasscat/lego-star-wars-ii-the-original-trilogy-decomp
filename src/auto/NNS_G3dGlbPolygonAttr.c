#include "m2c.h"

extern M2C_UNK NNS_G3dGlb;

void NNS_G3dGlbPolygonAttr(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_FIELD(&NNS_G3dGlb, s32 *, 0x9C) =
        (s32) (arg5 | (arg0 | (arg1 * 0x10) | (arg2 << 6)) | (arg3 << 0x18) | (arg4 << 0x10));
}
