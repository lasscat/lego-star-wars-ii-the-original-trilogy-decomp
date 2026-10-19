/* Reconstructed from USA ARM9 at 0x0202d754 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0202d754(void *arg0, s8 **arg1) {
    s8 *var_r2;

    var_r2 = *arg1;
    if (var_r2 != 0) {
        var_r2 -= 4;
    }
    if (var_r2 != 0) {
        var_r2 += 4;
    }
    if (var_r2 != 0) {
        M2C_FIELD(arg0, void **, 0)   = var_r2;
        M2C_FIELD(arg0, void **, 4)   = M2C_FIELD(var_r2, void **, 0);
        M2C_FIELD(var_r2, void **, 0) = arg0;
    } else {
        M2C_FIELD(arg0, void **, 0) = NULL;
        M2C_FIELD(arg0, void **, 4) = NULL;
    }
}
