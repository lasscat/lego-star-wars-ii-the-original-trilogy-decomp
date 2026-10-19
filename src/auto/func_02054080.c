/* Reconstructed from USA ARM9 at 0x02054080 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02054080(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r1;

    M2C_FIELD(arg0, u16 *, 0xE) = (u16) (arg1 | (arg2 << 8));
    if (M2C_FIELD(arg0, u16 *, 0xE) == 0x10) {
        temp_r1 = M2C_FIELD(arg0, u16 *, 0xA) & ~0xC0;
    } else {
        temp_r1 = (M2C_FIELD(arg0, u16 *, 0xA) & ~0xC0) | 0x40;
    }
    M2C_FIELD(arg0, u16 *, 0xA) = temp_r1;
    M2C_FIELD(arg0, u8 *, 0x1C) = M2C_FIELD(arg0, u8 *, 0x1C) | 4;
}
