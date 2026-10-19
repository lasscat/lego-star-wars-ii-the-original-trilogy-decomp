#include "engine.h"
#include "m2c.h"

M2C_UNK OS_DisableInterrupts(void);
void OS_RestoreInterrupts(M2C_UNK);

extern M2C_UNK data_02117e20;

s32 WM_GetConnectedAIDs(void) {
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = OS_DisableInterrupts();
    if (M2C_FIELD(&data_02117e20, void **, 4) != NULL) {
        var_r4 = M2C_FIELD(M2C_FIELD(&data_02117e20, void **, 4), s32 *, 0x14C);
    } else {
        var_r4 = 0;
    }
    OS_RestoreInterrupts(temp_r0);
    return (s32) (u16) var_r4;
}
