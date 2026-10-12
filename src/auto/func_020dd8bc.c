#include "m2c.h"

M2C_UNK func_020ccdfc();                            /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */

void func_020dd8bc(s32 arg0, void *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0) == 0) {
        func_020ccdfc(arg0);
    }
    func_020ce818(M2C_FIELD(arg1, s32 *, 4));
}
