#include "m2c.h"

s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
s32 PXI_SendWordByFifo(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_02117450;

void TP_RequestSamplingAsync(void) {
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = OS_DisableInterrupts();
    if (PXI_SendWordByFifo(6, 0x03000000, 0) >= 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        OS_RestoreInterrupts(temp_r4);
        M2C_FIELD(&data_02117450, u16 *, 0x38) = (u16) (M2C_FIELD(&data_02117450, u16 *, 0x38) | 1);
        if (M2C_FIELD(&data_02117450, M2C_UNK(**)(M2C_UNK, M2C_UNK, M2C_UNK), 4) == NULL) {
            return;
        }
        M2C_FIELD(&data_02117450, M2C_UNK(**)(M2C_UNK, M2C_UNK, M2C_UNK), 4)(0, 4, 0);
        return;
    }
    M2C_FIELD(&data_02117450, u16 *, 0x3A) = (u16) (M2C_FIELD(&data_02117450, u16 *, 0x3A) | 1);
    M2C_FIELD(&data_02117450, u16 *, 0x38) = (u16) (M2C_FIELD(&data_02117450, u16 *, 0x38) & ~1);
    OS_RestoreInterrupts(temp_r4);
}
