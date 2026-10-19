/* Reconstructed from USA ARM9 at 0x0206d06c (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020b8f70(M2C_UNK, M2C_UNK);            /* extern */

void func_0206d06c(void *arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 0x886);
    if (temp_r0 == 0) {
        func_020b8f70(0xB5, 0);
        return;
    }
    if (temp_r0 != 1) {
        return;
    }
    func_020b8f70(0xB4, 0);
}
