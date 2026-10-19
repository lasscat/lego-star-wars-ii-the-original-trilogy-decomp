#include "m2c.h"

extern M2C_UNK WM_DMA_NO;

s32 MBi_GetGgid(void) {
    return M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), s32 *, 8);
}
