/* Reconstructed from USA ARM9 at 0x02062a7c (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02062d10();                                /* extern */

s32 func_02062a7c(s32 arg0, s32 arg1) {
    s32 temp_r0;

    if (arg0 == arg1) {
        return arg0;
    }
    temp_r0 = func_02062d10() & 0x7FFF;
    return arg0 + ((temp_r0 * ((arg1 - arg0) + 1)) >> 0xF);
}
