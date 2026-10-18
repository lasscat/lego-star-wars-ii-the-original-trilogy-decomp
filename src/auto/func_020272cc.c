/* Reconstructed from USA ARM9 at 0x020272cc (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"
int func_020272cc(void *object) {
    int count = M2C_FIELD(object, u8 *, 0x55);
    int index = M2C_FIELD(object, u8 *, 0x56);
    if ((s32) index < count - 1) {
        M2C_FIELD(object, u8 *, 0x56) = index + 1;
        return 1;
    }
    return 0;
}
