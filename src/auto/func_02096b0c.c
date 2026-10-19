/* Reconstructed from USA ARM9 at 0x02096b0c (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_02096b0c(void *arg0, s32 arg1, s32 arg2) {
    void *temp_r0;
    void *var_ip;

    var_ip = M2C_FIELD(arg0, void **, 4);
    if (var_ip != NULL) {
        do {
            temp_r0 = M2C_FIELD(var_ip, void **, 0);
            if ((M2C_FIELD(temp_r0, u8 *, 0x21) == arg2) && (M2C_FIELD(temp_r0, u8 *, 0x20) == arg1)) {
                return temp_r0;
            }
            var_ip = M2C_FIELD(var_ip, void **, 4);
        } while (var_ip != NULL);
    }
    return NULL;
}
