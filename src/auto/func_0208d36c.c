/* Reconstructed from USA ARM9 at 0x0208d36c (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_0208d36c(void *arg0, s32 arg1) {
    void *temp_r0;
    void *var_r3;

    var_r3 = M2C_FIELD(arg0, void **, 4);
    while (var_r3 != NULL) {
        temp_r0 = M2C_FIELD(var_r3, void **, 0);
        if (M2C_FIELD(temp_r0, u8 *, 0x24) == arg1) {
            return temp_r0;
        }
        var_r3 = M2C_FIELD(var_r3, void **, 4);
    }
    return NULL;
}
