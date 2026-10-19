#include "m2c.h"

M2C_UNK NNS_FndFreeToExpHeap(s32);                         /* extern */

void AllocatorFreeForExpHeap(void *arg0) {
    NNS_FndFreeToExpHeap(M2C_FIELD(arg0, s32 *, 4));
}
