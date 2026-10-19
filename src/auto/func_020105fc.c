/* Reconstructed from USA ARM9 at 0x020105fc (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020cb1d4(s32 *);

void func_020105fc(void *arg0) {
    s32 sp0;
    u16 *p;

    do {
    } while (func_020cb1d4(&sp0) != 0);
    p = (u16 *) ((u8 *) arg0 + 0x1A8);
    *p &= ~4;
    if (sp0 == 0) {
        *p |= 8;
    }
}
