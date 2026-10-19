#include "m2c.h"

M2C_UNK NNS_G3dGeBufferOP_N(s32, s32 *, M2C_UNK);         /* extern */
extern M2C_UNK NNS_G3dGlb;
extern s32 data_027e0c18;
extern s32 data_027e0c60;
extern s32 data_027e0c90;

void NNS_G3dGlbFlushVP(void) {
    s32 sp0;

    NNS_G3dGeBufferOP_N(0x1610, &data_027e0c18, 0x11);
    NNS_G3dGeBufferOP_N(0x19, &data_027e0c60, 0xC);
    sp0 = 2;
    NNS_G3dGeBufferOP_N(0x10, &sp0, 1);
    NNS_G3dGeBufferOP_N(0x15, &data_027e0c90, 0x20);
    M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) = (s32) ((M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & ~1) | 2);
}
