#include "m2c.h"

s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
M2C_UNK func_020d1020(M2C_UNK);                     /* extern */

void func_020d0e6c(s32 arg0, M2C_UNK arg1) {
    s32 temp_r4;

    temp_r4 = func_020ce804();
    func_020d1020(arg1);
    func_020ce818(temp_r4);
}
