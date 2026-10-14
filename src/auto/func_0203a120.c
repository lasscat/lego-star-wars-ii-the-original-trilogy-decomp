#include "m2c.h"

M2C_UNK func_0203a4c4();                            /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020aa7c0(s32, s32);                    /* extern */
s32 func_020aaeb4();                                /* extern */
extern M2C_UNK data_020fe0d8;

void *func_0203a120(void *arg0) {
    s32 temp_r5;
    void **var_r1;
    void *temp_r0;
    void *var_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe0d8;
    if (M2C_FIELD(arg0, u8 *, 0x24) == 0) {
        func_0203a4c4(arg0);
    }
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x20);
    if (temp_r5 != 0) {
        func_020aa7c0(func_020aaeb4(), temp_r5);
    }
    var_r1 = M2C_FIELD(arg0, void ***, 0x10);
    if (var_r1 != NULL) {
        var_r2  = *var_r1;
        temp_r0 = arg0 + 0x10;
        if (var_r2 != temp_r0) {
            do {
                var_r1 = var_r2 + 4;
                var_r2 = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0);
        }
        *var_r1 = M2C_FIELD(arg0, void **, 0x14);
    }
    func_0205e84c(arg0);
    return arg0;
}
