#include "m2c.h"

M2C_UNK OSi_EnqueueTail(s32, void *);                 /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
extern M2C_UNK OSi_ThreadInfo;

s32 OS_TryLockMutex(void *arg0) {
    s32 state;
    s32 r2;
    s32 d;
    s32 ret;

    state = OS_DisableInterrupts();
    r2    = M2C_FIELD(arg0, s32 *, 8);
    d     = M2C_FIELD(&OSi_ThreadInfo, s32 *, 4);
    if (r2 == 0) {
        M2C_FIELD(arg0, s32 *, 8)   = d;
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1);
        OSi_EnqueueTail(d, arg0);
        ret = 1;
    } else if (r2 != d) {
        ret = 0;
    } else {
        ret                         = 1;
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1);
    }
    OS_RestoreInterrupts(state);
    return ret;
}
