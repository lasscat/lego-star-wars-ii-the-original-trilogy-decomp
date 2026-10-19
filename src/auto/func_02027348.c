/* Reconstructed from USA ARM9 at 0x02027348 (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02027348(void *arg0, void *arg1) {
    volatile u16 sp0;
    u16 temp_r3;

    temp_r3                   = M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0) = temp_r3;
    sp0                       = temp_r3;
    M2C_FIELD(arg0, u8 *, 2)  = M2C_FIELD(arg1, u8 *, 2);
    M2C_FIELD(arg0, u8 *, 3)  = M2C_FIELD(arg1, u8 *, 3);
    M2C_FIELD(arg0, u8 *, 4)  = M2C_FIELD(arg1, u8 *, 4);
    M2C_FIELD(arg0, u8 *, 5)  = M2C_FIELD(arg1, u8 *, 5);
}
