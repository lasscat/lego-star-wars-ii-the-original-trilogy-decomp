/* Reconstructed from USA ARM9 at 0x020abc58 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020abda4(s32, M2C_UNK);                    /* extern */

s32 func_020abc58(void *arg0, s32 arg1) {
    void *temp_r2;
    void *var_r3;

    var_r3 = M2C_FIELD(arg0, void **, 4);
    while (var_r3 != NULL) {
        temp_r2 = M2C_FIELD(var_r3, void **, 0);
        if (arg1 == M2C_FIELD(temp_r2, u16 *, 0x10)) {
            return func_020abda4(M2C_FIELD(temp_r2, s32 *, 8), 1);
        }
        var_r3 = M2C_FIELD(var_r3, void **, 4);
    }
    return 0;
}
