#include "m2c.h"

/*
 * a0 : table of 10-byte records (one per level/slot).
 *      byte at +0x2A is the record index used when a4 == 4.
 *      halfword at record+4 holds the behaviour flags.
 * a1 : pointer to the counter that is adjusted.
 * a2 : lower bound of the counter range.
 * a3 : exclusive upper bound of the counter range.
 * a4 : record index.
 *
 * flag 0x20: decrement the counter, wrapping to a3 - 1 when it drops below a2.
 * flag 0x10: increment the counter, wrapping back to a2 when it reaches a3.
 * Returns 1 when a counter was changed, 0 otherwise.
 */
s32 func_0205cf78(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 flags;
    s32 ret;
    s32 v;
    s32 w;

    if (a4 == 4) {
        a4 = *(u8 *) (a0 + 0x2a);
    }
    flags = *(u16 *) (a0 + a4 * 10 + 4);
    ret   = 0;
    if (flags & 0x20) {
        v = *(s32 *) a1 - 1;
        if (v < a2) {
            v = a3 - 1;
        }
        *(s32 *) a1 = v;
        ret         = 1;
    } else if (flags & 0x10) {
        v = *(s32 *) a1 + 1;
        w = a2;
        if (v != a3) {
            w = v;
        }
        *(s32 *) a1 = w;
        ret         = 1;
    }
    return ret;
}
