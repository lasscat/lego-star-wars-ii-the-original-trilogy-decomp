/* Reconstructed from USA ARM9 at 0x020aaa08 (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_020aaa08(void *arg0, s32 arg1, s32 arg2) {
    void *temp_r0;
    void *var_ip;

    var_ip = M2C_FIELD(arg0, void **, 0x398);
    if (var_ip != NULL) {
        do {
            temp_r0 = M2C_FIELD(var_ip, void **, 0);
            if ((temp_r0 != NULL) && (M2C_FIELD(temp_r0, u8 *, 0x28) == arg1) && (M2C_FIELD(temp_r0, u8 *, 0x29) == arg2)) {
                return temp_r0;
            }
            var_ip = M2C_FIELD(var_ip, void **, 4);
        } while (var_ip != NULL);
    }
    return NULL;
}
