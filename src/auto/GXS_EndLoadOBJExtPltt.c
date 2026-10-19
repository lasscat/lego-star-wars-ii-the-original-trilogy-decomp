#include "engine.h"
#include "m2c.h"

void GX_SetBankForSubOBJExtPltt(M2C_UNK);
void MI_WaitDma(M2C_UNK);

extern s32 GXi_DmaId;
extern M2C_UNK sSubBGExtPltt;

void GXS_EndLoadOBJExtPltt(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForSubOBJExtPltt(M2C_FIELD(&sSubBGExtPltt, s32 *, 0x18));
    M2C_FIELD(&sSubBGExtPltt, s32 *, 0x18) = 0;
}
