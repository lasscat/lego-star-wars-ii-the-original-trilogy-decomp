#include "m2c.h"

/* Tests one bit of a 32-bit bitmap: bit (a1 * 11 + a2) of the table at a0.
   a1 is an unsigned index and must be below 0x10. */
s32 func_0208c6ac(s32 a0, s32 a1, s32 a2) {
    if ((u32) a1 >= 0x10) {
        return 0;
    }
    return ((((s32 *) a0)[(a1 * 11 + a2) >> 5]) & (1 << ((a1 * 11 + a2) & 0x1f))) ? 1 : 0;
}
