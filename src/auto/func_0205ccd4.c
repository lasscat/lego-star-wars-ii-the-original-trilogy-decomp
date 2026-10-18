/* Reconstructed from USA ARM9 at 0x0205ccd4 (36 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0205ccd4(void **arg0) {
    u32 i;
    for (i = 0; i < 5; i++) {
        void *p = arg0[i];
        if (p != NULL) {
            *(u8 *) ((u8 *) p + 0x26) = 0;
        }
    }
}
