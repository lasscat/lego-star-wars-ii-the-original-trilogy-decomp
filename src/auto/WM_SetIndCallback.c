#include "m2c.h"

s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
void *WMi_GetSystemWork();                              /* extern */
s32 WMi_CheckInitialized();                                /* extern */

s32 WM_SetIndCallback(s32 arg0) {
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = OS_DisableInterrupts();
    temp_r0 = WMi_CheckInitialized();
    if (temp_r0 != 0) {
        OS_RestoreInterrupts(temp_r5);
        return temp_r0;
    }
    M2C_FIELD(WMi_GetSystemWork(), s32 *, 0xC8) = arg0;
    OS_RestoreInterrupts(temp_r5);
    return 0;
}
