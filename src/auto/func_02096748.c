#include "m2c.h"

M2C_UNK func_0209678c(void *, void *);              /* extern */

void func_02096748(void *arg0, s32 arg1, s32 arg2) {
    void *temp_ip;
    void *var_lr;

    var_lr = M2C_FIELD(arg0, void **, 4);
    if (var_lr == NULL) {
        return;
    }
loop_2:
    temp_ip = M2C_FIELD(var_lr, void **, 0);
    if ((M2C_FIELD(temp_ip, u8 *, 0x21) == arg2) && (M2C_FIELD(temp_ip, u8 *, 0x20) == arg1)) {
        func_0209678c(arg0, temp_ip);
        return;
    }
    var_lr = M2C_FIELD(var_lr, void **, 4);
    if (var_lr == NULL) {
        return;
    }
    goto loop_2;
}
