#include "m2c.h"
M2C_UNK OS_InitMutex(M2C_UNK *);
M2C_UNK PXI_Init();
M2C_UNK PXI_SetFifoRecvCallback(M2C_UNK, M2C_UNK *);
s32 PXI_IsCallbackReady(M2C_UNK, M2C_UNK);
extern M2C_UNK data_0211748c;
extern M2C_UNK data_021174b4;
extern M2C_UNK data_021174cc;
extern M2C_UNK func_020d3b70;
void PM_Init(void) {
    s32 var_r3;
    if (M2C_FIELD(&data_0211748c, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0211748c, u16 *, 0)    = 1U;
    M2C_FIELD(&data_0211748c, s32 *, 0x18) = 0;
    M2C_FIELD(&data_0211748c, s32 *, 0x1C) = 0;
    PXI_Init();
    while (PXI_IsCallbackReady(8, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(8, &func_020d3b70);
    for (var_r3 = 0; var_r3 < 5; var_r3++) {
        ((u16 *) &data_021174cc)[var_r3 * 4] = 0;
    }
    OS_InitMutex(&data_021174b4);
    M2C_FIELD(&data_0211748c, s32 *, 0x10) = *(s32 *) 0x027FFC3C;
}
