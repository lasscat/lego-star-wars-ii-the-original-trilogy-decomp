#include "m2c.h"

/* Scrolls the selection index stored at *counter within [lo, hi),
 * using the flags of entry `idx` of the 10-byte-entry table at `table`.
 * Entry index 4 is indirected through the byte at table + 0x2a. */
s32 func_0205cfe8(u8 *table, s32 *counter, s32 lo, s32 hi, s32 idx) {
    u16 flags;
    s32 value;
    s32 wrapped;
    s32 result;

    if (idx == 4) {
        idx = *(u8 *) (table + 0x2a);
    }
    flags = *(u16 *) (table + idx * 10 + 4);

    result = 0;
    if (flags & 0x40) {
        value = *counter - 1;
        if (value < lo) {
            value = hi - 1;
        }
        *counter = value;
        result   = 1;
    } else if (flags & 0x80) {
        value   = *counter + 1;
        wrapped = lo;
        if (value != hi) {
            wrapped = value;
        }
        *counter = wrapped;
        result   = 1;
    }
    return result;
}
