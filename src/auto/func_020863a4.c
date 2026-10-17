#include "m2c.h"

M2C_UNK func_020865ac(M2C_UNK, u8);                 /* extern */
extern M2C_UNK data_020f4910;

void func_020863a4(M2C_UNK arg0) {
    u8 var_r5;

    var_r5 = 0;
    do {
        if (*((u8 *) ((s8 *) &data_020f4910 + (var_r5 * 4))) == 0) {
            func_020865ac(arg0, var_r5);
        }
        var_r5 += 1;
    } while ((u32) var_r5 < 0xFAU);
}
