#include "m2c.h"

M2C_UNK OS_UnLockCartridge();                            /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */

void CTRDGi_UnlockByProcessor(s32 arg0, void *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0) == 0) {
        OS_UnLockCartridge(arg0);
    }
    OS_RestoreInterrupts(M2C_FIELD(arg1, s32 *, 4));
}
