#include "m2c.h"

M2C_UNK func_020cd59c();                            /* extern */
s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */

void func_020cd54c(void *arg0) {
    s32 temp_r4;

    temp_r4                      = func_020ce804();
    M2C_FIELD(arg0, s32 *, 0x64) = 1;
    func_020cd59c();
    func_020ce818(temp_r4);
}
