/* Reconstructed from USA ARM9 at 0x020be768 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"
extern M2C_UNK data_0210e1f8;
void func_020be768(s32 arg0, void *arg1) {
    volatile s32 sp0;
    volatile s32 sp4;
    s32 temp_r0;
    temp_r0                      = M2C_FIELD(arg1, s32 *, 0x6C) + ((s32 *) &data_0210e1f8)[M2C_FIELD(arg1, s32 *, 0x4C)];
    sp0                          = temp_r0;
    sp4                          = temp_r0;
    M2C_FIELD(arg1, s32 *, 0x6C) = temp_r0;
}
