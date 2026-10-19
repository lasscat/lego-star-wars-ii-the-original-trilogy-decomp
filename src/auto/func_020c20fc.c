/* Reconstructed from USA ARM9 at 0x020c20fc (104 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_020c20e4(void *, void *);                /* extern */

void *func_020c20fc(void *arg0, u32 arg1) {
    void *var_r0;
    void *var_r4;

    var_r4 = func_020c20e4(arg0, NULL);
    if (var_r4 != NULL) {
        do {
            if (((u32) M2C_FIELD(var_r4, u32 *, 0x18) <= arg1) && (arg1 < (u32) M2C_FIELD(var_r4, u32 *, 0x1C))) {
                var_r0 = func_020c20fc(var_r4 + 0xC, arg1);
                if (var_r0 == NULL) {
                    var_r0 = var_r4;
                }
                return var_r0;
            }
            var_r4 = func_020c20e4(arg0, var_r4);
        } while (var_r4 != NULL);
    }
    return NULL;
}
