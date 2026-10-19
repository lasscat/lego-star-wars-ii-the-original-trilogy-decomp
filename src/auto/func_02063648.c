/* Reconstructed from USA ARM9 at 0x02063648 (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02052f0c(s32, s32, M2C_UNK);                    /* extern */
extern s32 data_027e02a8;

M2C_UNK func_02063648(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK r;
    data_027e02a8 |= 0x100;
    r = func_02052f0c(arg0 * 0x10, arg1 * 0x10, arg2);
    data_027e02a8 &= ~0x100;
    return r;
}
