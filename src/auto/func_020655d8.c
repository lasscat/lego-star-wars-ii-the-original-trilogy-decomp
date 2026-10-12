#include "m2c.h"

M2C_UNK func_0206556c(u32, M2C_UNK);                /* extern */

void func_020655d8(u32 *arg0) {
    u32 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 >= 5U) {
        return;
    }
    func_0206556c(temp_r0, 0);
    *arg0 = 5;
}
