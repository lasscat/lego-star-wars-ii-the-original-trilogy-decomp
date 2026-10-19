#include "m2c.h"

M2C_UNK OS_FreeToHeap(s32, s32, M2C_UNK);           /* extern */

void AllocatorFreeForSDKHeap(void *arg0, M2C_UNK arg1) {
    OS_FreeToHeap(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 4), arg1);
}
