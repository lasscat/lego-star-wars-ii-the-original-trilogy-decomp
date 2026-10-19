#include "m2c.h"

M2C_UNK NNS_FndAllocFromFrmHeapEx(s32, M2C_UNK, s32);           /* extern */

void AllocatorAllocForFrmHeap(void *arg0, M2C_UNK arg1) {
    NNS_FndAllocFromFrmHeapEx(M2C_FIELD(arg0, s32 *, 4), arg1, M2C_FIELD(arg0, s32 *, 8));
}
