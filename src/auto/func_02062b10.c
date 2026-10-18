/* Reconstructed from USA ARM9 at 0x02062b10 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02062d7c();                                /* extern */

u32 func_02062b10(s32 arg0) {
    u32 t = func_02062d7c() & 0x7FFF;
    return (t * (arg0 + 1) * 2) >> 0x10;
}
