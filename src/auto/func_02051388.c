#include "m2c.h"

M2C_UNK func_0200b174(s32, M2C_UNK, u8, M2C_UNK, s32, s32, s32); /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void func_02051388(void *arg0) {
    s32 temp_r0;
    s32 var_ip;

    temp_r0 = func_0205e80c(0xF8, 0, 4);
    if (temp_r0 == 0) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0xA) != 0) {
        var_ip = 1;
    } else {
        var_ip = 0;
    }
    func_0200b174(temp_r0, 0, M2C_FIELD(arg0, u8 *, 8), 0, (s32) M2C_FIELD(arg0, u8 *, 9), 3, var_ip);
}
