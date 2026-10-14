#include "m2c.h"

extern s32 data_0210daf0;
extern M2C_UNK data_0210dafc;

void func_020b4564(s32 arg0) {
    s32 temp_r1;
    s32 var_r4;

    if (arg0 == 4) {
        var_r4 = 0;
        do {
            func_020b4564(var_r4);
            var_r4 += 1;
        } while (var_r4 < 3);
        return;
    }
    temp_r1 = *((M2C_UNK *) ((s8 *) &data_0210dafc + (arg0 * 4)));
    if (temp_r1 != 0) {
        data_0210daf0 = temp_r1;
    }
}
