#include "m2c.h"

/* Searches a 1024-bit allocation bitmap for a run of `count` clear bits
   starting at bit `pos`; returns the first bit of the run, or 0xFFFF. */
s32 func_02064eac(u8 *bits, s32 count, u32 pos) {
    s32 remaining = 1;
    s32 start     = 0;

    while (pos + count <= 0x400 && remaining > 0) {
        start     = pos;
        remaining = count;
        while (remaining > 0) {
            u32 b = bits[pos >> 3];
            u32 bit;

            if (b == 0xFF) {
                pos += 8;
                break;
            }
            if (b == 0) {
                pos += 8;
                remaining -= 8;
                continue;
            }
            bit = pos & 7;
            do {
                pos++;
                if (b & (1 << bit)) {
                    goto next;
                }
                bit++;
                remaining--;
            } while (bit < 8 && remaining > 0);
        }
    next:;
    }
    if (remaining <= 0) {
        return start;
    }
    return 0xFFFF;
}
