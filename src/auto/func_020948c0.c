/* Reconstructed from USA ARM9 at 0x020948c0 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_020948c0(void *arg0) {
    void *temp_r0;
    void *var_r2;

    var_r2 = M2C_FIELD(arg0, void **, 0x74);
    while (var_r2 != NULL) {
        temp_r0 = M2C_FIELD(var_r2, void **, 0);
        if (M2C_FIELD(M2C_FIELD(temp_r0, void **, 0xC), u8 *, 1) != 0) {
            return temp_r0;
        }
        var_r2 = M2C_FIELD(var_r2, void **, 4);
    }
    return NULL;
}
