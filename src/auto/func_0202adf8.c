/* Reconstructed from USA ARM9 at 0x0202adf8 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020272cc(void *);                          /* extern */
s32 func_020272f4(void *, s32);                     /* extern */

s32 func_0202adf8(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x90) != 0) {
        return 0;
    }
    if (func_020272f4(arg0, arg1) == 0) {
        return 1;
    }
    M2C_FIELD(arg0, s8 *, 0x91) = 0;
    return func_020272cc(arg0);
}
