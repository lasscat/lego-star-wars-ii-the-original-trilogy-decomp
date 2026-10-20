#include "m2c.h"

/* Global word whose value is copied into the destination array. */
extern u32 data_020fec64;

/* Fills 16 bytes (4 words) at dst with the value of data_020fec64 and
 * returns dst.  The byte count is turned into a word count with a division
 * by 4, which the compiler keeps as a runtime division (signed x / 4). */
u32 *func_020755d8(u32 *dst) {
    s32 c;
    u32 *p;

    c = 16;
    c = c / 4;
    p = dst;
    while (c > 0) {
        *p = data_020fec64;
        p++;
        c--;
    }
    return dst;
}
