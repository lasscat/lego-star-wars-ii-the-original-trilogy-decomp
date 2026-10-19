/* Reconstructed from USA ARM9 at 0x0205268c (80 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02094930(M2C_UNK *, s32 *, M2C_UNK, void *); /* extern */
extern M2C_UNK data_021093b0;

s32 func_0205268c(void *arg0, s32 arg1, M2C_UNK arg2) {
    s16 *p = arg0;
    s32 a;
    s32 b;
    s32 c;
    s32 sp0[3];

    a      = p[0] << 0xC;
    c      = p[2] << 0xC;
    b      = p[1] << 0xC;
    sp0[0] = a;
    sp0[1] = b;
    sp0[2] = c;
    func_02094930(&data_021093b0, sp0, arg2, arg0 + 8);
    return 0;
}
