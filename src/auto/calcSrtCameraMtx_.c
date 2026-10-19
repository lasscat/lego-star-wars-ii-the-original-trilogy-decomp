#include "m2c.h"

M2C_UNK MTX_ScaleApply43(M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK MTX_Inverse43(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK MTX_Concat43(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK NNS_G3dGlb;
extern M2C_UNK data_027e0c60;
extern M2C_UNK data_027e0cd0;
extern M2C_UNK data_027e0d44;
extern M2C_UNK data_027e0d74;

void calcSrtCameraMtx_(void) {
    MTX_Concat43(&data_027e0cd0, &data_027e0c60, &data_027e0d44);
    MTX_ScaleApply43(&data_027e0d44, &data_027e0d44, M2C_FIELD(&NNS_G3dGlb, s32 *, 0xEC), M2C_FIELD(&NNS_G3dGlb, s32 *, 0xF0),
                     M2C_FIELD(&NNS_G3dGlb, s32 *, 0xF4));
    MTX_Inverse43(&data_027e0d44, &data_027e0d74);
}
