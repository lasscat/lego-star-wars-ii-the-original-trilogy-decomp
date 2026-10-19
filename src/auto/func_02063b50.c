/* Reconstructed from USA ARM9 at 0x02063b50 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205d6f8(void *, M2C_UNK);             /* extern */

void *func_02063b50(void *arg0) {
    s32 *p;
    s8 *q;
    s32 i;

    func_0205d6f8(arg0, 0xA);
    p       = (s32 *) arg0;
    q       = (s8 *) arg0;
    q[0x60] = 0;
    for (i = 0; i < 4; i++) {
        p[i + 0xE]  = 0;
        q[i + 0x48] = 0;
        q[i + 0x4C] = 0;
    }
    return arg0;
}
