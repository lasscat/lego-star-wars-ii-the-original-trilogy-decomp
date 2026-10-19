/* Reconstructed from USA ARM9 at 0x0208bfec (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0208bfec(void *arg0) {
    s32 *base;
    void *t;
    s32 i;

    base = (s32 *) arg0;
    for (i = 0; i < 4; i++) {
        t = (void *) base[i + 0x15];
        if (t != 0) {
            *(s32 *) ((s8 *) t + 8) = *(s32 *) ((s8 *) t + 8) | 1;
        }
    }
    *(s32 *) ((s8 *) arg0 + 0x78) = *(s32 *) ((s8 *) arg0 + 0x78) & ~4;
}
