#include "m2c.h"

M2C_UNK PXI_Init();                            /* extern */
M2C_UNK PXI_SetFifoRecvCallback(M2C_UNK, M2C_UNK *);          /* extern */
s32 PXI_IsCallbackReady(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_02117450;
extern M2C_UNK TPi_TpCallback;

void TP_Init(void) {
    if (M2C_FIELD(&data_02117450, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_02117450, u16 *, 0) = 1U;
    PXI_Init();
    M2C_FIELD(&data_02117450, s16 *, 0x10) = 0;
    M2C_FIELD(&data_02117450, s32 *, 4)    = 0;
    M2C_FIELD(&data_02117450, s32 *, 0x14) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x36) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x34) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x3A) = 0;
    M2C_FIELD(&data_02117450, s16 *, 0x38) = 0;
    do {

    } while (PXI_IsCallbackReady(6, 1) == 0);
    PXI_SetFifoRecvCallback(6, &TPi_TpCallback);
}
