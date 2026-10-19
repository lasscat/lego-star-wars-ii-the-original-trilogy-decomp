#include "m2c.h"

M2C_UNK MBi_StartParentCore();                            /* extern */
extern M2C_UNK WM_DMA_NO;

void MB_StartParentFromIdle(s32 arg0) {
    M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 0xC), s32 *, 0x1320) = 1;
    MBi_StartParentCore(arg0);
}
