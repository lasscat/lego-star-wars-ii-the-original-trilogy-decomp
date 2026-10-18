/* Reconstructed from USA ARM9 at 0x0203638c (36 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0203638c(void *object, s32 value, s32 index) {
    if (M2C_FIELD(object, u8 *, 0x30) != 6) {
        return;
    }
    if (index == 0) {
        M2C_FIELD(object, s32 *, 0x54) = value;
        return;
    }
    if (index == 1) {
        M2C_FIELD(object, s32 *, 0x58) = value;
    }
}
