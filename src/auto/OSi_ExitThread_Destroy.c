#include "m2c.h"

M2C_UNK OSi_RemoveSpecifiedLinkFromQueue(s32, void *);                 /* extern */
M2C_UNK OSi_RemoveThreadFromList(void *);                      /* extern */
M2C_UNK OS_WakeupThread(void *);                      /* extern */
M2C_UNK OSi_RescheduleThread();                            /* extern */
M2C_UNK OS_DisableScheduler();                            /* extern */
M2C_UNK OS_EnableScheduler();                            /* extern */
M2C_UNK OSi_UnlockAllMutex(void *);                      /* extern */
M2C_UNK OS_Terminate();                            /* extern */
extern M2C_UNK OSi_SystemCallbackInSwitchThread;

void OSi_ExitThread_Destroy(void) {
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = *M2C_FIELD(&OSi_SystemCallbackInSwitchThread, void ***, 8);
    OS_DisableScheduler();
    OSi_UnlockAllMutex(temp_r4);
    temp_r0 = M2C_FIELD(temp_r4, s32 *, 0x78);
    if (temp_r0 != 0) {
        OSi_RemoveSpecifiedLinkFromQueue(temp_r0, temp_r4);
    }
    OSi_RemoveThreadFromList(temp_r4);
    M2C_FIELD(temp_r4, s32 *, 0x64) = 2;
    OS_WakeupThread(temp_r4 + 0x9C);
    OS_EnableScheduler();
    OSi_RescheduleThread();
    OS_Terminate();
}
