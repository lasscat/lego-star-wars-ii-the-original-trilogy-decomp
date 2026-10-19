/* Reconstructed from USA ARM9 at 0x02062ab4 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02062d7c();                                /* extern */

s32 func_02062ab4(s32 arg0, s32 arg1) {
    s32 t = func_02062d7c() & 0x7FFF;
    return arg0 + ((t * ((arg1 - arg0) + 1)) >> 0xF);
}
