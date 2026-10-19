/* Reconstructed from USA ARM9 at 0x020d27ec (132 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK OS_WakeupThread(void *);                      /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
M2C_UNK FSi_ReleaseCommand(void *, s32);                 /* extern */
s32 FSi_NextCommand(void *);                          /* extern */
M2C_UNK FSi_ExecuteAsyncCommand();                            /* extern */

void FS_NotifyArchiveAsyncEnd(void *arg0, s32 arg1) {
    s32 temp_r0;
    s32 var_r0;
    void *temp_r5;

    if (M2C_FIELD(arg0, volatile s32 *, 0x1C) & 0x100) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        void *p;

        p                                     = M2C_FIELD(arg0, void **, 0x24);
        M2C_FIELD(arg0, volatile s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x1C) & ~0x100);
        FSi_ReleaseCommand(p, arg1);
        if (FSi_NextCommand(arg0) == 0) {
            return;
        }
        FSi_ExecuteAsyncCommand();
        return;
    }
    temp_r5                                  = M2C_FIELD(arg0, void **, 0x24);
    temp_r0                                  = OS_DisableInterrupts();
    M2C_FIELD(temp_r5, volatile s32 *, 0x14) = arg1;
    M2C_FIELD(arg0, volatile s32 *, 0x1C)    = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x1C) & ~0x200);
    OS_WakeupThread(arg0 + 0xC);
    OS_RestoreInterrupts(temp_r0);
}
