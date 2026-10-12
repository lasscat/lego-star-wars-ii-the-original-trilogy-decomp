#include "m2c.h"

extern M2C_UNK data_0210db84;
extern u8 data_0210dd82;

void func_020bb4ac(s8 arg0) {
    s32 var_r1;
    u8 *var_r2;

    var_r2 = &data_0210dd82;
    M2C_FIELD(&data_0210db84, s8 *, 0xC1) = arg0;
    var_r1 = 0xB;
    do {
        var_r1 -= 1;
        *var_r2 = (*var_r2 & ~1) | 1;
        var_r2 -= 0x1C;
    } while (var_r1 >= 0);
}
