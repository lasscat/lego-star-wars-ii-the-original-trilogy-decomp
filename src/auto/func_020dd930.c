#include "m2c.h"

M2C_UNK func_020ce3b4(M2C_UNK, M2C_UNK);            /* extern */
s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
s32 func_020dd698();                                /* extern */
extern s32 data_0211e458;

void func_020dd930(s32 arg0) {
    M2C_UNK var_r1;
    s32 temp_r4;

    temp_r4 = func_020ce804();
    data_0211e458 = arg0;
    if (func_020dd698() == 0) {
        if (arg0 != 0) {
            var_r1 = 0x1000;
        } else {
            var_r1 = 0x5000;
        }
        func_020ce3b4(0xF000, var_r1);
    }
    func_020ce818(temp_r4);
}
