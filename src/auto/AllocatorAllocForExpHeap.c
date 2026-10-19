#include "m2c.h"

M2C_UNK NNS_FndAllocFromExpHeapEx(s32, M2C_UNK, s32);           /* extern */

void AllocatorAllocForExpHeap(void *arg0, M2C_UNK arg1) {
    NNS_FndAllocFromExpHeapEx(M2C_FIELD(arg0, s32 *, 4), arg1, M2C_FIELD(arg0, s32 *, 8));
}
