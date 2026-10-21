#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02095ee8 (48 bytes).
 *
 * The function marks two cells of a 10-wide byte grid with the value 100:
 * the cell at (a1 + a0 + a2 * 10) and the cell 100 bytes further on.
 * a0 is the grid base, a1 and a2 are grid coordinates; a coordinate of 10
 * (out of range) and the diagonal a1 == a2 are rejected.
 */
void func_02095ee8(s32 a0, s32 a1, s32 a2) {
    u8 *p = (u8 *) a1;
    u8 *q;
    s32 idx;

    if (a1 == a2) {
        return;
    }
    if (a1 == 0xA || a2 == 0xA) {
        return;
    }
    idx    = a0 + a2 * 10;
    p[idx] = 100;
    q      = (u8 *) (idx + a1);
    q[100] = 100;
}
