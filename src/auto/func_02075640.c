#include "m2c.h"

/* Global word array whose value is copied into the destination array.
 * The symbol holds the pair of words used by the two init helpers
 * (func_020755d8 copies word 0, func_02075640 copies word 1). */
extern u32 data_020fec64[];

/* Fills 16 bytes (4 words) at dst with the value of data_020fec64[1] and
 * returns dst.  The byte count is turned into a word count with a division
 * by 4, which the compiler keeps as a runtime division (signed x / 4). */
u32 *func_02075640(u32 *dst) {
    s32 c;
    u32 *p;

    c = 16;
    c = c / 4;
    p = dst;
    while (c > 0) {
        *p = *(u32 *) ((u8 *) data_020fec64 + 4);
        p++;
        c--;
    }
    return dst;
}
