/* Reconstructed from USA ARM9 at 0x020b8724 (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020b7f90(u8, M2C_UNK);                 /* extern */
extern u8 *data_0210daf0;
extern M2C_UNK data_0210dc2f;

void func_020b8724(void) {
    s32 var_r6;
    u8 *var_r7;

    var_r7 = (u8 *) &data_0210dc2f;
    var_r6 = 0xF;
    do {
        if (data_0210daf0[0x39] == var_r7[4]) {
            func_020b7f90((u8) var_r6, 0);
        }
        var_r7 -= 1;
        var_r6 -= 1;
    } while (var_r6 >= 0);
}
