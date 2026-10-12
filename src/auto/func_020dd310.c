#include "m2c.h"

s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
s32 func_020dd15c();                                /* extern */
M2C_UNK func_020dd1a4(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s32 data_0211e440;

void func_020dd310(M2C_UNK arg0) {
    s32 temp_r4;

    temp_r4 = func_020ce804();
    if (func_020dd15c() != 0) {
        func_020dd1a4(data_0211e440 + 0xC4, 0, arg0, 0);
    }
    func_020ce818(temp_r4);
}
