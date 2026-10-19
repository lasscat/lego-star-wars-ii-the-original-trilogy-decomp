#include "m2c.h"
M2C_UNK OS_WakeupThread(void *);
M2C_UNK OSi_DequeueItem(s32, void *);
s32 OS_DisableInterrupts();
M2C_UNK OS_RestoreInterrupts(s32);
extern M2C_UNK OSi_ThreadInfo;
void OS_UnlockMutex(void *arg0) {
    s32 temp = OS_DisableInterrupts();
    s32 d    = M2C_FIELD(&OSi_ThreadInfo, s32 *, 4);
    if (M2C_FIELD(arg0, s32 *, 8) == d) {
        s32 n                       = M2C_FIELD(arg0, s32 *, 0xC) - 1;
        M2C_FIELD(arg0, s32 *, 0xC) = n;
        if (n == 0) {
            OSi_DequeueItem(d, arg0);
            M2C_FIELD(arg0, s32 *, 8) = 0;
            OS_WakeupThread(arg0);
        }
    }
    OS_RestoreInterrupts(temp);
}