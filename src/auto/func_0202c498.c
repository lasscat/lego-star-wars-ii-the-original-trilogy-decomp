/* Reconstructed from USA ARM9 at 0x0202c498 (104 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_0202cb90(void *, s32, s8);               /* extern */
void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_0205e84c();                            /* extern */

void func_0202c498(void *arg0, s8 arg1) {
    void *var_r0;

    if (arg1 == 0xB) {
        if (M2C_FIELD(arg0, void **, 0x1C) != NULL) {
            func_0205e84c();
        }
        M2C_FIELD(arg0, void **, 0x1C) = NULL;
        return;
    }
    if (M2C_FIELD(arg0, void **, 0x1C) != NULL) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s8 *, 8) = arg1;
        return;
    }
    var_r0 = func_0205e80c(0xC, 1, 4);
    if (var_r0 != NULL) {
        var_r0 = func_0202cb90(var_r0, M2C_FIELD(arg0, s32 *, 0x20), arg1);
    }
    M2C_FIELD(arg0, void **, 0x1C) = var_r0;
}
