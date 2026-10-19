#include "m2c.h"

M2C_UNK OS_SetDPermissionsForProtectionRegion(M2C_UNK, M2C_UNK);            /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
s32 CTRDG_IsOptionCartridge();                                /* extern */
extern s32 CTRDGi_EnableFlag;

void CTRDG_Enable(s32 arg0) {
    M2C_UNK var_r1;
    s32 temp_r4;

    temp_r4           = OS_DisableInterrupts();
    CTRDGi_EnableFlag = arg0;
    if (CTRDG_IsOptionCartridge() == 0) {
        if (arg0 != 0) {
            var_r1 = 0x1000;
        } else {
            var_r1 = 0x5000;
        }
        OS_SetDPermissionsForProtectionRegion(0xF000, var_r1);
    }
    OS_RestoreInterrupts(temp_r4);
}
