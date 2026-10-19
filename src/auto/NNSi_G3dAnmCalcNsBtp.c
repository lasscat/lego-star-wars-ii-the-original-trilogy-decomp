#include "engine.h"
#include "m2c.h"

M2C_UNK NNSi_G3dGetTexPatAnmTexNameByIdx(M2C_UNK, M2C_UNK);
M2C_UNK NNSi_G3dGetTexPatAnmPlttNameByIdx(M2C_UNK, M2C_UNK);
M2C_UNK NNSi_G3dGetTexPatAnmFV(M2C_UNK, M2C_UNK, M2C_UNK);
void SetTexParamaters_(M2C_UNK, M2C_UNK, M2C_UNK);
void SetPlttParamaters_(M2C_UNK, M2C_UNK, M2C_UNK);

void NNSi_G3dAnmCalcNsBtp(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r5;
    u8 temp_r1;
    void *temp_r0;

    temp_r5 = M2C_FIELD(arg1, s32 *, 8);
    temp_r0 =
        (void *) NNSi_G3dGetTexPatAnmFV(temp_r5, (s32) (u16) arg2, (s32) ((u32) (M2C_FIELD(arg1, s32 *, 0) * 0x10) >> 0x10));
    SetTexParamaters_(M2C_FIELD(arg1, s32 *, 0x14),
                      NNSi_G3dGetTexPatAnmTexNameByIdx(temp_r5, (s32) M2C_FIELD(temp_r0, u8 *, 2)), arg0);
    temp_r1 = M2C_FIELD(temp_r0, u8 *, 3);
    if (temp_r1 == 0xFF) {
        return;
    }
    SetPlttParamaters_(M2C_FIELD(arg1, s32 *, 0x14), NNSi_G3dGetTexPatAnmPlttNameByIdx(temp_r5, (s32) temp_r1), arg0);
}
