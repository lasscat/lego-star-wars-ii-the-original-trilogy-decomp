#include "engine.h"
#include "m2c.h"

M2C_UNK OS_DisableInterrupts(void);
void OS_RestoreInterrupts(M2C_UNK);

extern M2C_UNK data_0211748c;

s32 func_020d3a08(void) {
    s32 temp_r0;

    temp_r0 = OS_DisableInterrupts();
    if (M2C_FIELD(&data_0211748c, s32 *, 0x18) != 0) {
        OS_RestoreInterrupts(temp_r0);
        return 0;
    }
    M2C_FIELD(&data_0211748c, s32 *, 0x18) = 1;
    OS_RestoreInterrupts(temp_r0);
    return 1;
}
