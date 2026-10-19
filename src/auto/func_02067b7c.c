/* Reconstructed from USA ARM9 at 0x02067b7c (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02067b7c(void *arg0, u32 arg1) {
    s32 sum;
    u32 i;
    u8 *p;

    sum = 0;
    if (arg1 == 0) {
        goto ret;
    }
    for (i = 0; i < arg1; i++) {
        p = *(u8 **) arg0 + i;
        sum += p[4];
    }
ret:
    return *(s32 *) ((s8 *) arg0 + 4) + sum;
}
