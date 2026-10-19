/* Reconstructed from USA ARM9 at 0x0208c840 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0208c72c(void *, u32);                     /* extern */
s32 func_0208c77c(void *, u32);                     /* extern */

u32 func_0208c840(void *arg0) {
    u32 total = 0;
    u32 i;

    for (i = 0; i < 0x10; i++) {
        total += func_0208c72c(arg0, i);
        if (func_0208c77c(arg0, i) != 0) {
            total += 1;
        }
    }
    return total;
}
