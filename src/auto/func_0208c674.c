/* Reconstructed from USA ARM9 at 0x0208c674.
 * Sets one bit of a 32-bit word table (index 0..15, bit = idx*11+10) and
 * flags the table as modified.
 */
#include "m2c.h"

void func_0208c674(s32 *arg0, u32 arg1) {
    s32 t;
    u32 m;
    s32 w;
    t                            = arg1 * 0xb + 0xa;
    m                            = 1 << (t & 0x1f);
    w                            = arg0[t >> 5];
    arg0[t >> 5]                 = w & ~m;
    arg0[t >> 5]                 = arg0[t >> 5] | m;
    *(u8 *) ((u8 *) arg0 + 0x18) = 1;
}
