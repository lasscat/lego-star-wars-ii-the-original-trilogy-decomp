#include "m2c.h"

extern M2C_UNK WM_DMA_NO;

void MBi_SetMaxScanTime(s16 arg0) {
    M2C_FIELD(&WM_DMA_NO, s16 *, 0x26) = arg0;
}
