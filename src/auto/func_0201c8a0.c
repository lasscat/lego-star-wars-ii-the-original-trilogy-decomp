/* Reconstructed from USA ARM9 at 0x0201c8a0 (140 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0201c814();                                /* extern */
M2C_UNK func_0201c92c(u16 *, M2C_UNK, u32, M2C_UNK); /* extern */
extern s32 data_027e02a4;
extern s32 data_027e02a8;

void func_0201c8a0(u16 *arg0, M2C_UNK arg1) {
    u32 var_r6;
    M2C_UNK var_r7;

    if (func_0201c814() != 0) {
        return;
    }
    var_r7 = 0;
    if (data_027e02a8 & (4 << data_027e02a4)) {
        data_027e02a8 |= 0x80;
        var_r7 = 1;
    }
    var_r6 = 0;
    do {
        func_0201c92c(arg0, arg1, var_r6, var_r7);
        var_r6 += 1;
    } while (var_r6 < 4U);
    data_027e02a8 &= ~0x80;
    *arg0 |= 0x40;
}
