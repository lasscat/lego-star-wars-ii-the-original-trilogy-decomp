#include "m2c.h"

M2C_UNK func_020aa7c0(void *, s32 *);               /* extern */

void func_020aa84c(void *arg0, s32 arg1) {
    s32 *temp_r3;
    void *var_ip;

    var_ip = M2C_FIELD(arg0, void **, 0x398);
    if (var_ip == NULL) {
        return;
    }
loop_2:
    temp_r3 = M2C_FIELD(var_ip, s32 **, 0);
    if ((temp_r3 != NULL) && (*temp_r3 == arg1)) {
        func_020aa7c0(arg0, temp_r3);
        return;
    }
    var_ip = M2C_FIELD(var_ip, void **, 4);
    if (var_ip == NULL) {
        return;
    }
    goto loop_2;
}
