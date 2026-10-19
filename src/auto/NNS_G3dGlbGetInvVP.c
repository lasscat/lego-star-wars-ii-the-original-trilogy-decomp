#include "m2c.h"

s32 NNS_G3dGlbGetInvV();                                /* extern */
s32 NNS_G3dGlbGetInvP();                                /* extern */
M2C_UNK MTX_Copy43To44_(s32, M2C_UNK *);              /* extern */
M2C_UNK MTX_Concat44(s32, M2C_UNK *, M2C_UNK *);   /* extern */
extern M2C_UNK NNS_G3dGlb;
extern M2C_UNK data_027e0e14;

M2C_UNK *NNS_G3dGlbGetInvVP(void) {
    u8 sp0[64];
    s32 temp_r4;
    s32 temp_r5;

    if (!(M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 0x40)) {
        temp_r5 = NNS_G3dGlbGetInvV();
        temp_r4 = NNS_G3dGlbGetInvP();
        MTX_Copy43To44_(temp_r5, sp0);
        MTX_Concat44(temp_r4, sp0, &data_027e0e14);
        M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) = (s32) (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) | 0x40);
    }
    return &data_027e0e14;
}
