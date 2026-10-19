#include "m2c.h"

extern M2C_UNK WM_DMA_NO;

s32 MBi_IsSendEnabled(void) {
    s32 var_r0;
    s32 var_r2;
    s32 var_r3;

    var_r0 = 0;
    var_r3 = 0;
    var_r2 = 0;
    if ((M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x528) == 1) &&
        (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u8 *, 0x50C) == 0)) {
        var_r3 = 1;
    }
    if ((var_r3 != 0) && (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x526) == 0)) {
        var_r2 = 1;
    }
    if ((var_r2 != 0) && (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x52A) != 0)) {
        var_r0 = 1;
    }
    return var_r0;
}
