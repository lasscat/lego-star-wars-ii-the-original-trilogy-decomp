#include "engine.h"
#include "m2c.h"

M2C_UNK OS_DisableInterrupts(void);
void OS_RestoreInterrupts(M2C_UNK);

extern M2C_UNK sFreeList;

s32 AllocCommand(void) {
    M2C_UNK *temp_r2;
    M2C_UNK *temp_r4;
    s32 temp_r0;

    temp_r0 = OS_DisableInterrupts();
    temp_r4 = M2C_FIELD(&sFreeList, M2C_UNK **, 0);
    if (temp_r4 == NULL) {
        OS_RestoreInterrupts(temp_r0);
        return 0;
    }
    temp_r2                              = *temp_r4;
    M2C_FIELD(&sFreeList, M2C_UNK **, 0) = temp_r2;
    if (temp_r2 == NULL) {
        M2C_FIELD(&sFreeList, s32 *, 0x10) = 0;
    }
    OS_RestoreInterrupts(temp_r0);
    return (s32) temp_r4;
}
