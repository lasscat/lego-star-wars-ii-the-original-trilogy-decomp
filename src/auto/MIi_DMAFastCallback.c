/* Reconstructed from USA ARM9 at 0x020cf170 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK MIi_GXDmaParams;

s32 MIi_DMAFastCallback(void) {
    s32 r;
    M2C_FIELD(&MIi_GXDmaParams, s32 *, 0) = 0;
    r                                     = M2C_FIELD(&MIi_GXDmaParams, s32 *, 0x14);
    if (M2C_FIELD(&MIi_GXDmaParams, s32(**)(), 0x10) != NULL) {
        r = M2C_FIELD(&MIi_GXDmaParams, s32(**)(), 0x10)();
    }
    return r;
}
