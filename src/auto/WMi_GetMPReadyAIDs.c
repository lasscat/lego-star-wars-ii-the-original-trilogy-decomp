#include "m2c.h"

M2C_UNK DC_InvalidateRange(s32, M2C_UNK);                /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
extern M2C_UNK data_02117e20;

u16 WMi_GetMPReadyAIDs(void) {
    void *temp_r4;
    u16 var_r4;
    s32 temp_r5;

    temp_r5 = OS_DisableInterrupts();
    if (M2C_FIELD(&data_02117e20, void **, 4) == NULL) {
        var_r4 = 0;
    } else {
        temp_r4 = M2C_FIELD(M2C_FIELD(&data_02117e20, void **, 4), void **, 4);
        DC_InvalidateRange(temp_r4 + 0x86, 2);
        var_r4 = M2C_FIELD(temp_r4, u16 *, 0x86);
    }
    OS_RestoreInterrupts(temp_r5);
    return var_r4;
}
