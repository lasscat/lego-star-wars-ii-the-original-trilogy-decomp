/* Reconstructed from USA ARM9 at 0x020948f4 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_020948f4(void *arg0, s32 arg1) {
    void *temp_r0;
    void *var_r3;

    if (arg1 == 0) {
        return NULL;
    }
    var_r3 = M2C_FIELD(arg0, void **, 0x74);
    while (var_r3 != NULL) {
        temp_r0 = M2C_FIELD(var_r3, void **, 0);
        if (M2C_FIELD(temp_r0, u16 *, 0x10) == arg1) {
            return temp_r0;
        }
        var_r3 = M2C_FIELD(var_r3, void **, 4);
    }
    return NULL;
}
