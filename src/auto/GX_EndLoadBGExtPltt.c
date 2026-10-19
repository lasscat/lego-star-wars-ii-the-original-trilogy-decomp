#include "engine.h"
#include "m2c.h"

void GX_SetBankForBGExtPltt(M2C_UNK);
void MI_WaitDma(M2C_UNK);

extern s32 GXi_DmaId;
extern M2C_UNK sSubBGExtPltt;

void GX_EndLoadBGExtPltt(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    GX_SetBankForBGExtPltt(M2C_FIELD(&sSubBGExtPltt, s32 *, 0x14));
    M2C_FIELD(&sSubBGExtPltt, s32 *, 0x14) = 0;
    M2C_FIELD(&sSubBGExtPltt, s32 *, 0x10) = 0;
    M2C_FIELD(&sSubBGExtPltt, s32 *, 0xC)  = 0;
}
