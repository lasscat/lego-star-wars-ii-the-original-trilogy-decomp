#include "m2c.h"

extern M2C_UNK WM_DMA_NO;

s32 MBi_IsStarted(void) {
    if (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u8 *, 0x50D) == 1) {
        return 1;
    }
    return 0;
}
