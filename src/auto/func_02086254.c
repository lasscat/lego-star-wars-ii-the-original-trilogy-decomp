/* Reconstructed from USA ARM9 at 0x02086254 (36 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02086254(void *object) {
    u32 index = 1;
    do {
        M2C_FIELD(object, u8 *, 0x4524 + index) = 0;
        ++index;
    } while (index < 0x39);
}
