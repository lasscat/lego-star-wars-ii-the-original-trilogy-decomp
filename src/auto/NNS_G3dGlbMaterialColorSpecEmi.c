#include "m2c.h"

extern M2C_UNK NNS_G3dGlb;

void NNS_G3dGlbMaterialColorSpecEmi(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r2;

    if (arg2 != 0) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    M2C_FIELD(&NNS_G3dGlb, s32 *, 0x98) = (s32) (arg0 | (arg1 << 0x10) | (var_r2 << 0xF));
}
