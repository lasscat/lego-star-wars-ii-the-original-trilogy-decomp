/* Reconstructed from USA ARM9 at 0x0204a5f8 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0204a5f8(void *arg0, u16 *arg1) {
    volatile u16 sp0;
    u16 temp_r1;

    M2C_FIELD(arg0, s8 *, 0xD)  = 1;
    temp_r1                     = *arg1;
    sp0                         = temp_r1;
    M2C_FIELD(arg0, u16 *, 0xE) = temp_r1;
}
