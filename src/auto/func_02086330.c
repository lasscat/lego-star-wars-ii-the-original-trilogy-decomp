#include "m2c.h"
M2C_UNK func_02086458(M2C_UNK, u8);
M2C_UNK func_02086558(M2C_UNK, u8);
extern u8 data_020eedac;

void func_02086330(M2C_UNK arg0) {
    u8 var_r7;
    u8 *p;
    var_r7 = 0;
    do {
        p = &data_020eedac + (var_r7 * 0x14);
        if ((*p == 0) && (p[1] == 1)) {
            func_02086458(arg0, var_r7);
        } else if ((*p == 0) && (p[1] == 0)) {
            func_02086558(arg0, var_r7);
        }
        var_r7 += 1;
    } while ((u32) var_r7 < 0x64U);
}
