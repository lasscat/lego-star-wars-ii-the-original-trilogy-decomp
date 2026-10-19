#include "m2c.h"

M2C_UNK OSi_ExitThread_ArgSpecified(s32, M2C_UNK);                /* extern */
M2C_UNK OS_DisableInterrupts();                            /* extern */
extern M2C_UNK OSi_SystemCallbackInSwitchThread;

void OS_ExitThread(void) {
    OS_DisableInterrupts();
    OSi_ExitThread_ArgSpecified(M2C_FIELD(&OSi_SystemCallbackInSwitchThread, s32 *, 0x28), 0);
}
