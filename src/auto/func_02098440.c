/* Reconstructed from USA ARM9 at 0x02098440.
 * Looks up a 16-bit value in a table and converts it to 16.16 fixed point
 * (value * 65536 / 360).  The division by 360 is done with the compiler's
 * magic-number multiply.
 */
#include "m2c.h"

extern u16 data_020f72a8[];

void func_02098440(u16 *out, u32 idx) {
    s32 v = data_020f72a8[idx];
    *out  = (u16) ((v << 16) / 360);
}
