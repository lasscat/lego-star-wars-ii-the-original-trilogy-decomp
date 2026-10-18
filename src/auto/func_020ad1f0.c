/* Reconstructed from USA ARM9 at 0x020ad1f0 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020ad1f0(void *arg0) {
    u16 v;
    s32 count;
    s32 i;

    v     = M2C_FIELD(arg0, u16 *, 0x66);
    count = 0;
    i     = 0;
    do {
        if (v & (1 << i)) {
            count += 1;
        }
        i += 1;
    } while (i < 16);
    return count;
}
