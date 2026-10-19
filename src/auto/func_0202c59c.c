/* Reconstructed from USA ARM9 at 0x0202c59c (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0202d7c0(s32, s32, s32);                   /* extern */

s32 func_0202c59c(void *arg0, s32 arg1, s32 arg2) {
    if (((M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 8) & 0x803) == 1) && (M2C_FIELD(arg0, s32 *, 0x24) != 0)) {
        return func_0202d7c0(M2C_FIELD(arg0, s32 *, 0x24), arg1, arg2);
    }
    return 0;
}
