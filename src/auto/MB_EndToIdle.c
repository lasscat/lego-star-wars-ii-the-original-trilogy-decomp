#include "m2c.h"

s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
M2C_UNK OS_Terminate();                            /* extern */
M2C_UNK MBi_CommEnd();                            /* extern */
extern M2C_UNK WM_DMA_NO;

void MB_EndToIdle(void) {
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    if (M2C_FIELD(M2C_FIELD(&WM_DMA_NO, void **, 0xC), s32 *, 0x1320) == 0) {
        OS_Terminate();
    }
    MBi_CommEnd();
    OS_RestoreInterrupts(temp_r4);
}
