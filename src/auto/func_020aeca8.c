/* Reconstructed from USA ARM9 at 0x020aeca8 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_0210b320;

s32 func_020aeca8(void) {
    s32 v;

    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x26;
    v                                      = M2C_FIELD(&data_0210b320, s32 *, 0x20);
    if (v == 6) {
        return 1;
    }
    return v == 4;
}
