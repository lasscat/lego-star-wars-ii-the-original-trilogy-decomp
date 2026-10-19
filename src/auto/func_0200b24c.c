/* Reconstructed from USA ARM9 at 0x0200b24c (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_0200b24c(void *arg0) {
    void **var_r2;
    void *var_r1;

    var_r2 = M2C_FIELD(arg0, void ***, 0);
    if (var_r2 == NULL) {
        return arg0;
    }
    var_r1 = *var_r2;
    if (var_r1 != arg0) {
        do {
            var_r2 = var_r1 + 4;
            var_r1 = M2C_FIELD(var_r1, void **, 4);
        } while (var_r1 != arg0);
    }
    *var_r2 = M2C_FIELD(arg0, void **, 4);
    return arg0;
}
