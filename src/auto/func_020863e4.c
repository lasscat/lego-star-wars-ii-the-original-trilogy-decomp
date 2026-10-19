/* Reconstructed from USA ARM9 at 0x020863e4 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02086600(M2C_UNK, u8);                 /* extern */
extern M2C_UNK data_020f6ba8;

void func_020863e4(M2C_UNK arg0) {
    void *p;
    u8 var_r6;

    p      = &data_020f6ba8;
    var_r6 = 0;
    do {
        if (M2C_FIELD(p + (var_r6 * 0x24), u16 *, 0x20) == 0) {
            func_02086600(arg0, var_r6);
        }
        var_r6 += 1;
    } while ((u32) var_r6 < 0x28U);
}
