#include "m2c.h"

/* func_0207ef78 (0x0207ef78, 0xf0 bytes)
 *
 * Returns the magnitude of the difference between the two values at +0x34
 * and +0x30, scaled down to the next power of ten: 1000000, 100000, 10000,
 * 1000, 100, 10 or 1 (0 for a difference of zero or less).
 */

s32 func_0207ef78(void *p) {
    s32 diff = M2C_FIELD(p, s32 *, 0x34) - M2C_FIELD(p, s32 *, 0x30);

    if (diff / 10000000 > 0) {
        return 1000000;
    }
    if (diff / 1000000 > 0) {
        return 100000;
    }
    if (diff / 100000 > 0) {
        return 10000;
    }
    if (diff / 10000 > 0) {
        return 1000;
    }
    if (diff / 1000 > 0) {
        return 100;
    }
    if (diff / 100 > 0) {
        return 10;
    }
    if (diff / 10 > 0) {
        return 10;
    }
    return diff > 0;
}
