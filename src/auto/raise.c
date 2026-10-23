#include "m2c.h"

s32 OS_TryLockMutex(void *);    /* extern */
void OS_LockMutex(void *);      /* extern */
void OS_UnlockMutex(void *);    /* extern */
void exit(s32);                /* extern */

extern M2C_UNK data_0211ec50;
extern M2C_UNK OSi_ThreadInfo;
extern M2C_UNK __cs_id;
typedef struct {
    u32 pad[7];
    s32 f1c;
} Cs;

extern Cs __cs_ref;
extern void (*signal_funcs[])(s32);

s32 raise(s32 sig) {
    void (*handler)(s32);
    s32 idx;

    if (sig < 1 || sig > 7) {
        return -1;
    }
    if (OS_TryLockMutex(&data_0211ec50) == 0) {
        M2C_FIELD(&__cs_id, s32 *, 0x1c) = M2C_FIELD(M2C_FIELD(&OSi_ThreadInfo, void **, 0x4), s32 *, 0x6c);
        __cs_ref.f1c                     = 1;
    } else {
        if (M2C_FIELD(&__cs_id, s32 *, 0x1c) == M2C_FIELD(M2C_FIELD(&OSi_ThreadInfo, void **, 0x4), s32 *, 0x6c)) {
            __cs_ref.f1c = __cs_ref.f1c + 1;
        } else {
            OS_LockMutex(&data_0211ec50);
            M2C_FIELD(&__cs_id, s32 *, 0x1c) = M2C_FIELD(M2C_FIELD(&OSi_ThreadInfo, void **, 0x4), s32 *, 0x6c);
            __cs_ref.f1c                     = 1;
        }
    }
    idx     = sig - 1;
    handler = signal_funcs[idx];
    if (handler != (void (*)(s32)) 1) {
        signal_funcs[idx] = 0;
    }
    if (--__cs_ref.f1c == 0) {
        OS_UnlockMutex(&data_0211ec50);
    }
    if (handler == (void (*)(s32)) 1 || (handler == 0 && sig == 1)) {
        return 0;
    }
    if (handler == 0) {
        exit(0);
    }
    handler(sig);
    return 0;
}
