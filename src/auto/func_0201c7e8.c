/* Reconstructed from USA ARM9 at 0x0201c7e8 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0201c7e8(u16 *arg0, u16 *arg1) {
    u32 i;

    i = 0;
    do {
        arg0[i + 1] = arg1[i + 1];
        i += 1;
    } while (i < 4);
    arg0[0] = arg1[0];
}
