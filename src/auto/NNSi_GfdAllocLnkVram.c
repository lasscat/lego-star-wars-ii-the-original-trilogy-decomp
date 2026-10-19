/* Reconstructed from USA ARM9 at 0x020c3110 (20 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 NNSi_GfdAllocLnkVramAligned(s32, s32, s32, s32, s32);
s32 NNSi_GfdAllocLnkVram(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return NNSi_GfdAllocLnkVramAligned(arg0, arg1, arg2, arg3, 0);
}
