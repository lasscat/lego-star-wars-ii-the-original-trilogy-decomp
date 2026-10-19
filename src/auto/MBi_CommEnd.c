#include "m2c.h"

s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
s32 MBi_CallReset();                                /* extern */
s32 MBi_IsTaskAvailable();                                /* extern */
M2C_UNK MBi_EndTaskThread(M2C_UNK *);                   /* extern */
extern M2C_UNK WM_DMA_NO;
extern M2C_UNK MBi_OnReset;

s32 MBi_CommEnd(void) {
    s32 temp_r4;
    s32 var_r5;

    var_r5  = 1;
    temp_r4 = OS_DisableInterrupts();
    if (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x526) == 0) {
        M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), s32 *, 0x5E4) = 0;
        M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 8), u16 *, 0x526) = 1U;
        if (MBi_IsTaskAvailable() != 0) {
            MBi_EndTaskThread(&MBi_OnReset);
            var_r5 = 0;
        } else {
            var_r5 = MBi_CallReset();
        }
    }
    OS_RestoreInterrupts(temp_r4);
    return var_r5;
}
