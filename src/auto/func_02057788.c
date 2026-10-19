/* Reconstructed from USA ARM9 at 0x02057788 (88 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_020aaeb4();                              /* extern */

void func_02057788(s32 arg0, void *arg1) {
    volatile s32 spC;
    volatile s32 sp8;
    volatile s32 sp4;
    volatile s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;

    M2C_FIELD(func_020aaeb4(), s8 *, 0x2D4)  = 1;
    temp_r0                                  = M2C_FIELD(arg1, u8 *, 0) << 0xC;
    sp4                                      = temp_r0;
    spC                                      = temp_r0;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x2D8) = sp4;
    temp_r0_2                                = M2C_FIELD(arg1, u8 *, 1) << 0xC;
    sp0                                      = temp_r0_2;
    sp8                                      = temp_r0_2;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x2DC) = sp0;
}
