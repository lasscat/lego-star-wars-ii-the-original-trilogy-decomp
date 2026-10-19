/* Reconstructed from USA ARM9 at 0x0202c5d8 (96 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_0202c710(void *, void *, void *, M2C_UNK); /* extern */

void *func_0202c5d8(void *arg0, s32 arg1) {
    void *temp_r0;
    void *temp_r5;
    void *var_r6;

    var_r6 = M2C_FIELD(arg0, void **, 4);
    if (var_r6 != NULL) {
        var_r6 -= 4;
    }
    temp_r5 = var_r6;
    while (var_r6 != NULL) {
        temp_r0 = func_0202c710(arg0, temp_r5, var_r6, 0);
        if (M2C_FIELD(var_r6, s32 *, 4) == arg1) {
            return var_r6;
        }
        var_r6 = temp_r0;
    }
    return NULL;
}
