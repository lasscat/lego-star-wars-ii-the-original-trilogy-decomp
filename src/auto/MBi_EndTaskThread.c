#include "m2c.h"

s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
s32 MBi_IsTaskAvailable();                                /* extern */
M2C_UNK MBi_SetTask(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s32 mbi_task_work;

void MBi_EndTaskThread(M2C_UNK arg0) {
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    if (MBi_IsTaskAvailable() != 0) {
        MBi_SetTask(mbi_task_work + 0xC4, 0, arg0, 0);
    }
    OS_RestoreInterrupts(temp_r4);
}
