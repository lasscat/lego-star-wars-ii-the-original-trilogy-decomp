/* Reconstructed from USA ARM9 at 0x02098478 (140 bytes).
 *
 * The original keeps every u16 temporary of the two branches in its own
 * stack slot (eight half-word slots, 0x00..0x0e, frame size 0x10) and never
 * reads them back, so the temporaries are volatile here; the slot order
 * follows the declaration order below and must not be permuted.
 */
#include "m2c.h"

s32 func_02062a7c(s32, s32);                         /* extern */
u32 func_02062ae4(s32);                              /* extern */

void func_02098478(u16 *arg0, u32 arg1) {
    volatile u16 spE;
    volatile u16 spC;
    volatile u16 spA;
    volatile u16 sp8;
    volatile u16 sp6;
    volatile u16 sp4;
    volatile u16 sp2;
    volatile u16 sp0;
    u16 t;
    u16 u;
    u16 v;

    v = (u16) (arg1 << 7);
    if (func_02062ae4(0x64) < 0x32) {
        spE   = func_02062a7c(0, v);
        t     = spE;
        spA   = t;
        sp6   = *arg0 + t;
        u     = sp6;
        sp8   = u;
        *arg0 = u;
    } else {
        spC   = func_02062a7c(0, v);
        t     = spC;
        sp4   = t;
        sp0   = *arg0 - t;
        u     = sp0;
        sp2   = u;
        *arg0 = u;
    }
}
