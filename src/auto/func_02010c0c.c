/* Reconstructed from USA ARM9 at 0x02010c0c (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02010c0c(void *arg0, s32 arg1) {
    s32 count;
    u16 *base;
    s32 i;
    u8 *p;
    count = M2C_FIELD(arg0, u16 *, 6);
    base  = M2C_FIELD(arg0, u16 **, 0);
    i     = 0;
    if (count > 0) {
        p = (u8 *) base;
        do {
            if (arg1 == M2C_FIELD(p, u16 *, 0)) {
                return (i * 0xA) + (s32) base;
            }
            i++;
            p += 0xA;
        } while (i < count);
    }
    return 0;
}
