#include "m2c.h"

M2C_UNK MTX_Inverse43(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK NNS_G3dGlb;
extern M2C_UNK data_027e0c60;
extern M2C_UNK data_027e0d14;

M2C_UNK *NNS_G3dGlbGetInvV(void) {
    if (!(M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 8)) {
        MTX_Inverse43(&data_027e0c60, &data_027e0d14);
        M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) = (s32) (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) | 8);
    }
    return &data_027e0d14;
}
