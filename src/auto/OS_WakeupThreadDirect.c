#include "m2c.h"

M2C_UNK OSi_RescheduleThread();                            /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */

void OS_WakeupThreadDirect(void *arg0) {
    s32 temp_r4;

    temp_r4                      = OS_DisableInterrupts();
    M2C_FIELD(arg0, s32 *, 0x64) = 1;
    OSi_RescheduleThread();
    OS_RestoreInterrupts(temp_r4);
}
