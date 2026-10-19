#include "m2c.h"

M2C_UNK func_02055c48(s32);
extern M2C_UNK data_02101efc;

void func_02055abc(void) {
    s32 var_r4;
    s32 var_r5;
    M2C_UNK *var_r6;
    s32 var_r7;
    var_r5 = 0x05000000;
    var_r6 = &data_02101efc;
    var_r7 = var_r5 + 0x200;
    var_r4 = 0;
    do {
        M2C_FIELD(var_r6, s32 *, 0x200) = var_r5;
        M2C_FIELD(var_r6, s32 *, 0x404) = var_r7;
        func_02055c48(var_r4);
        var_r5 += 0x400;
        var_r6 = (M2C_UNK *) ((s32) var_r6 + 0x408);
        var_r4 += 1;
        var_r7 += 0x400;
    } while (var_r4 < 2);
}
