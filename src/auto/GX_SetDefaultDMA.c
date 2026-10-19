#include "m2c.h"

M2C_UNK MI_WaitDma(s32);                            /* extern */
M2C_UNK OS_DisableInterrupts();                     /* extern */
M2C_UNK OS_RestoreInterrupts();                     /* extern */
extern M2C_UNK sIsDispOn;

s32 GX_SetDefaultDMA(s32 arg0) {
    M2C_UNK m2c_irq;
    s32 temp_r4;

    temp_r4 = M2C_FIELD(&sIsDispOn, s32 *, 4);
    if (temp_r4 != -1) {
        MI_WaitDma(temp_r4);
    }
    m2c_irq                         = OS_DisableInterrupts();
    M2C_FIELD(&sIsDispOn, s32 *, 4) = arg0;
    OS_RestoreInterrupts(m2c_irq);
    return temp_r4;
}
