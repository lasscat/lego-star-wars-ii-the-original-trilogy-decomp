/* Reconstructed from USA ARM9 at 0x0204c6b8 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0204c6e8(s32 *, M2C_UNK);                       /* extern */

s32 *func_0204c6b8(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 *var_r3;

    var_r3 = arg0;
    do {
        *var_r3 = 0;
        var_r3 += 1;
    } while (var_r3 < arg0 + 6);
    func_0204c6e8(arg0, arg1);
    return arg0;
}
