/* Reconstructed from USA ARM9 at 0x020c2adc (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 func_020c2a50(void *, u32);
s32 func_020c2adc(void *object, u32 index) {
    void *nested = M2C_FIELD(object, void **, 4);
    if (index > M2C_FIELD(nested, u32 *, 0x28)) {
        return 0;
    }
    return func_020c2a50(nested, index);
}
