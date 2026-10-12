#include "m2c.h"

M2C_UNK func_02067908(void *, u32);                 /* extern */

void func_020679b8(void *arg0) {
    u32 var_r4;

    var_r4 = 1;
    if ((u32) M2C_FIELD(arg0, u8 *, 5) < 1U) {
        return;
    }
    do {
        func_02067908(arg0, var_r4);
        var_r4 += 1;
    } while (var_r4 <= (u32) M2C_FIELD(arg0, u8 *, 5));
}
