/* Reconstructed from USA ARM9 at 0x020c62dc (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020c62a0(void *, u32, M2C_UNK);        /* extern */

void func_020c62dc(void *arg0, M2C_UNK arg1) {
    u32 var_r4;

    var_r4 = 0;
    while ((u32) M2C_FIELD(arg0, u8 *, 0x18) > var_r4) {
        func_020c62a0(arg0, var_r4, arg1);
        var_r4 += 1;
    }
}
