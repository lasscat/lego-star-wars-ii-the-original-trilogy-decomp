/* Reconstructed from USA ARM9 at 0x020c2adc (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 NNS_FndAllocFromUnitHeap(void *, u32);
s32 AllocatorAllocForUnitHeap(void *object, u32 index) {
    void *nested = M2C_FIELD(object, void **, 4);
    if (index > M2C_FIELD(nested, u32 *, 0x28)) {
        return 0;
    }
    return NNS_FndAllocFromUnitHeap(nested, index);
}
