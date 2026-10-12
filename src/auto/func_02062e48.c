#include "m2c.h"

M2C_UNK func_02062e1c();                            /* extern */
M2C_UNK func_02062e2c();                            /* extern */
M2C_UNK func_02062e38();                            /* extern */

void func_02062e48(s32 arg0, s32 arg1) {
    if ((arg1 & 3) == 3) {
        func_02062e38(arg0);
        return;
    }
    if (arg1 & 1) {
        func_02062e1c(arg0);
        return;
    }
    if (!(arg1 & 2)) {
        return;
    }
    func_02062e2c(arg0);
}
