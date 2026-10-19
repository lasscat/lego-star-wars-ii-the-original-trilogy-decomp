/* compiler: 2.0/sp1p5 -O4,s */
/* Reconstructed from USA ARM9 at 0x02006b24 (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02006b24(void *object) {
    s32 index = 0;
    do {
        M2C_FIELD(object, s32 *, 0x6d0 + index * 4) = -1;
        ++index;
    } while (index < 5);
}
