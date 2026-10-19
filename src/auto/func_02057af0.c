/* Reconstructed from USA ARM9 at 0x02057af0 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_020aaeb4();                              /* extern */

s32 func_02057af0(s32 arg0, s32 *arg1) {
    volatile s32 sp0;
    volatile s32 sp4;
    void *p;
    s32 temp_r0;

    temp_r0                    = *arg1 << 0xC;
    sp4                        = temp_r0;
    sp0                        = temp_r0;
    p                          = func_020aaeb4();
    M2C_FIELD(p, s32 *, 0x284) = sp4;
    return (s32) p;
}
