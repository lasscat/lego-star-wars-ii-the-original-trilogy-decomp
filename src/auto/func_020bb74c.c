/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0210dd7c;

void func_020bb74c(void) {
    M2C_UNK *var_r3;
    s32 var_r2;

    var_r3 = &data_0210dd7c;
    var_r2 = 0xB;
    do {
        if (M2C_FIELD(var_r3, u8 *, 1) == 4) {
            M2C_FIELD(var_r3, u8 *, 1) = 1U;
        }
        var_r3 = (M2C_UNK *) ((s8 *) var_r3 - 0x1C);
        var_r2 -= 1;
    } while (var_r2 >= 0);
}
