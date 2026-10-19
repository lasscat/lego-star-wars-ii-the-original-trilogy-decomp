#include "engine.h"
#include "m2c.h"

void func_020ca300(M2C_UNK);
void MI_WaitDma(M2C_UNK);

extern s32 GXi_DmaId;
extern M2C_UNK sClrImg;

void GX_EndLoadClearImage(void) {
    if (GXi_DmaId != -1) {
        MI_WaitDma(GXi_DmaId);
    }
    func_020ca300(M2C_FIELD(&sClrImg, s32 *, 0));
    M2C_FIELD(&sClrImg, s32 *, 0)    = 0;
    M2C_FIELD(&sClrImg, s32 *, 0x10) = 0;
}
