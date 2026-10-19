#include "m2c.h"

extern M2C_UNK NNS_G3dGlb;

void NNS_G3dGlbGetViewPort(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    if (arg0 != NULL) {
        *arg0 = (s32) (u8) M2C_FIELD(&NNS_G3dGlb, u32 *, 0xA0);
    }
    if (arg1 != NULL) {
        *arg1 = (s32) (u8) ((u32) M2C_FIELD(&NNS_G3dGlb, u32 *, 0xA0) >> 8);
    }
    if (arg2 != NULL) {
        *arg2 = (s32) (u8) ((u32) M2C_FIELD(&NNS_G3dGlb, u32 *, 0xA0) >> 0x10);
    }
    if (arg3 == NULL) {
        return;
    }
    *arg3 = (s32) (u8) ((u32) M2C_FIELD(&NNS_G3dGlb, u32 *, 0xA0) >> 0x18);
}
