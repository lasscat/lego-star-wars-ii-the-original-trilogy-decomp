/* Reconstructed from USA ARM9 at 0x0201c65c (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0201c65c(void *object) {
    typedef void (*Method)(void *, s32);
    if (M2C_FIELD(object, u8 *, 0xa4) == 0) {
        return;
    }
    M2C_FIELD(object, u8 *, 0xa5) = 1;
    M2C_FIELD(M2C_FIELD(object, void **, 0), Method *, 0x2c)(object, 1);
}
