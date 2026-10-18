/* Reconstructed from USA ARM9 at 0x020abf08 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020abd64(s32, M2C_UNK);                    /* extern */

s32 func_020abf08(void *arg0, M2C_UNK arg1) {
    void *var_r4;
    s32 temp_r5;

    var_r4 = M2C_FIELD(arg0, void **, 4);
    while (var_r4 != NULL) {
        temp_r5 = M2C_FIELD(var_r4, s32 *, 0);
        if (func_020abd64(temp_r5, arg1) != 0) {
            return temp_r5;
        }
        var_r4 = M2C_FIELD(var_r4, void **, 4);
    }
    return 0;
}
