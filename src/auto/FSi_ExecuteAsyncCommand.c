#include "m2c.h"

M2C_UNK OS_WakeupThread(void *);                      /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
s32 FSi_TranslateCommand(void *, s32);                     /* extern */
void *FSi_NextCommand(s32);                           /* extern */

void FSi_ExecuteAsyncCommand(void *arg0) {
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r0;
    void *var_r6;

    var_r6  = arg0;
    temp_r4 = M2C_FIELD(var_r6, volatile s32 *, 8);
    if (var_r6 == NULL) {
        return;
    }
loop_3:
    temp_r5                                = OS_DisableInterrupts();
    M2C_FIELD(var_r6, volatile s32 *, 0xC) = (s32) (M2C_FIELD(var_r6, volatile s32 *, 0xC) | 0x40);
    if (M2C_FIELD(var_r6, volatile s32 *, 0xC) & 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        OS_WakeupThread(var_r6 + 0x18);
        OS_RestoreInterrupts(temp_r5);
        return;
    }
    M2C_FIELD(var_r6, volatile s32 *, 0xC) = (s32) (M2C_FIELD(var_r6, volatile s32 *, 0xC) | 8);
    OS_RestoreInterrupts(temp_r5);
    if (FSi_TranslateCommand(var_r6, M2C_FIELD(var_r6, volatile s32 *, 0x10)) == 6) {
        return;
    }
    var_r6 = FSi_NextCommand(temp_r4);
    if (var_r6 == NULL) {
        return;
    }
    goto loop_3;
}
