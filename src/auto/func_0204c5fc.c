/* Reconstructed from USA ARM9 at 0x0204c5fc (88 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0204c654(s32 *, M2C_UNK *);
M2C_UNK func_020accac(M2C_UNK *, M2C_UNK, s16 *, M2C_UNK);

s32 *func_0204c5fc(s32 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s16 sp[3];
    M2C_UNK sp8[0x12];
    s32 *var_r2;

    var_r2 = arg0;
    do {
        *var_r2++ = 0;
    } while ((u32) var_r2 < (u32) (arg0 + 6));
    sp[0] = 0;
    sp[1] = 0;
    sp[2] = 0;
    func_020accac(sp8, arg1, sp, arg2);
    func_0204c654(arg0, sp8);
    return arg0;
}
