#include "m2c.h"

M2C_UNK func_020aa7c0(void *, void *);              /* extern */

void func_020aa890(void *arg0, void *arg1) {
    void *temp_ip;
    void *var_lr;

    var_lr = M2C_FIELD(arg0, void **, 0x398);
    if (var_lr == NULL) {
        return;
    }
loop_2:
    temp_ip = M2C_FIELD(var_lr, void **, 0);
    if (temp_ip != NULL) {
        if ((M2C_FIELD(arg1, s32 *, 0) == M2C_FIELD(temp_ip, s32 *, 4)) &&
            (M2C_FIELD(arg1, s32 *, 4) == M2C_FIELD(temp_ip, s32 *, 8)) &&
            (M2C_FIELD(arg1, s32 *, 8) == M2C_FIELD(temp_ip, s32 *, 0xC))) {
            func_020aa7c0(arg0, temp_ip);
            return;
        }
        goto block_9;
    }
block_9:
    var_lr = M2C_FIELD(var_lr, void **, 4);
    if (var_lr == NULL) {
        return;
    }
    goto loop_2;
}
