#include "engine.h"
#include "m2c.h"

M2C_UNK OS_DisableInterrupts(void);
void OS_RestoreInterrupts(M2C_UNK);

extern M2C_UNK sFreeList;

s32 SND_IsFinishedCommandTag(s32 arg0) {
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = OS_DisableInterrupts();
    if ((u32) arg0 > (u32) M2C_FIELD(&sFreeList, u32 *, 4)) {
        if ((u32) (arg0 - M2C_FIELD(&sFreeList, u32 *, 4)) < 0x80000000U) {
            var_r4 = 0;
        } else {
            var_r4 = 1;
        }
    } else if ((u32) (M2C_FIELD(&sFreeList, u32 *, 4) - arg0) < 0x80000000U) {
        var_r4 = 1;
    } else {
        var_r4 = 0;
    }
    OS_RestoreInterrupts(temp_r0);
    return var_r4;
}
