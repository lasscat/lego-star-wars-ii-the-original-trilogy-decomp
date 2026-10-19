#include "m2c.h"

M2C_UNK calcSrtCameraMtx_();                            /* extern */
extern M2C_UNK NNS_G3dGlb;
extern M2C_UNK data_027e0d44;

M2C_UNK *NNS_G3dGlbGetWV(void) {
    if (!(M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 0x80)) {
        calcSrtCameraMtx_();
        M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) = (s32) (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) | 0x80);
    }
    return &data_027e0d44;
}
