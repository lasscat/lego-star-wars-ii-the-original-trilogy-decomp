#include "engine.h"
#include "m2c.h"

M2C_UNK OS_DisableInterrupts(void);
void OS_RestoreInterrupts(M2C_UNK);
void MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK IsChildAidValid(M2C_UNK);

extern s32 mbc;

s32 MB_CommGetChildUser(s32 arg0) {
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    if ((mbc != 0) && (IsChildAidValid(arg0) != 0)) {
        MI_CpuCopy8(((arg0 - 1) * 0x16) + (mbc + 0x1340), mbc + 0x1772, 0x16);
        OS_RestoreInterrupts(temp_r4);
        return mbc + 0x1772;
    }
    OS_RestoreInterrupts(temp_r4);
    return 0;
}
