#include "engine.h"
#include "m2c.h"

void GetTexSRTAnm_(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void NNSi_G3dAnmCalcNsBta(s32 arg0, s32 arg1, s32 arg2) {
    GetTexSRTAnm_(M2C_FIELD(arg1, s32 *, 8), (s32) (u16) arg2, (s32) M2C_FIELD(arg1, s32 *, 0) >> 0xC, arg0);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((M2C_FIELD(arg0, s32 *, 0x10) & ~0xC0000000) | 0x40000000);
    M2C_FIELD(arg0, s32 *, 0)    = (s32) (M2C_FIELD(arg0, s32 *, 0) | 8);
}
