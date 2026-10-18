/* Reconstructed from USA ARM9 at 0x0201b44c (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0205ab44(u16);                             /* extern */

s32 func_0201b44c(void *arg0) {
    s32 temp_r0;
    s32 first;
    s32 second;
    void *temp_r4;

    temp_r0 = func_0205ab44(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u16 *, 2));
    temp_r4 = temp_r0 + 0xC + M2C_FIELD((temp_r0 + (M2C_FIELD(arg0, u8 *, 0x1B) * 2)), u16 *, 0xC);
    first   = func_0205ab44(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u16 *, 0));
    second  = M2C_FIELD(temp_r4, u16 *, 4);
    return first + second;
}
