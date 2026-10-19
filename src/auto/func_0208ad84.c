/* Reconstructed from USA ARM9 at 0x0208ad84 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02053b14(s32);                             /* extern */

void *func_0208ad84(void *arg0) {
    s16 *tmp;
    s32 i;

    tmp = (s16 *) func_02053b14((s32) arg0 + 8);
    for (i = 0; i < 0xB; i++) {
        tmp[i + 0x28] = 0x40;
        tmp[i + 0x48] = 0x40;
    }
    return (s8 *) tmp + 0x50;
}
