#include "m2c.h"

extern M2C_UNK WM_DMA_NO;

s32 MBi_SetMPData(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16);
void MBi_ChildCallback(M2C_UNK);

s32 MBi_SendMP(s32 arg0, s32 arg1, s32 arg2) {
    u16 a1 = (u16) arg1;
    u16 a2 = (u16) arg2;
    s32 ret;

    if (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x528) == 0 ||
        M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x526) == 1) {
        return 1;
    }

    switch (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x524)) {
        case 1: {
            u16 val = (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x52C) == 0) ? 1000 : 0;
            ret     = MBi_SetMPData(M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), void **, 0x508), arg0, a1, val, a2);
            if (ret == 2) {
                M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u8 *, 0x50C) = 1;
            }
            return (ret == 2) ? 0 : ret;
        }
        case 2: {
            ret = MBi_SetMPData((M2C_UNK) MBi_ChildCallback, arg0, a1, 0, a2);
            if (ret == 2) {
                M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u8 *, 0x50C) = 1;
            }
            return (ret == 2) ? 0 : ret;
        }
        default:
            return 1;
    }
}
