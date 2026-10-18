/* Reconstructed from USA ARM9 at 0x02062b3c (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02062d10();                                /* extern */

s32 func_02062b3c(u32 arg0) {
    s32 t = func_02062d10() & 0x7FFF;
    if (arg0 >= (u32) ((u32) (t * 0x65) >> 0xF)) {
        return 1;
    }
    return 0;
}
