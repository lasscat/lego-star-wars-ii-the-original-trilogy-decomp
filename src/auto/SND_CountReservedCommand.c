#include "engine.h"
#include "m2c.h"

M2C_UNK OS_DisableInterrupts(void);
void OS_RestoreInterrupts(M2C_UNK);

extern M2C_UNK sFreeList;

s32 SND_CountReservedCommand(void) {
    M2C_UNK *var_r1;
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = OS_DisableInterrupts();
    var_r4  = 0;
    var_r1  = M2C_FIELD(&sFreeList, M2C_UNK **, 8);
    if (var_r1 != NULL) {
        do {
            var_r1 = *var_r1;
            var_r4 += 1;
        } while (var_r1 != NULL);
    }
    OS_RestoreInterrupts(temp_r0);
    return var_r4;
}
