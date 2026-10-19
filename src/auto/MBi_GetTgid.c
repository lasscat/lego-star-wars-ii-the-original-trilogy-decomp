#include "m2c.h"

extern M2C_UNK WM_DMA_NO;

u16 MBi_GetTgid(void) {
    return M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0xC);
}
