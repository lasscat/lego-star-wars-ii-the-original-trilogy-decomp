/* Reconstructed from USA ARM9 at 0x0208c77c.
 * Tests one bit of a 32-bit word table; index 0..15, bit = idx*11+10.
 */
#include "m2c.h"

s32 func_0208c77c(s32 *arg0, u32 arg1) {
    s32 t;
    if (arg1 >= 0x10) {
        return 0;
    }
    t = arg1 * 0xb + 0xa;
    return (arg0[t >> 5] & (1 << (t & 0x1f))) ? 1 : 0;
}
