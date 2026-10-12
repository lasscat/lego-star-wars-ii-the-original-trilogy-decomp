#include "m2c.h"

M2C_UNK func_02075524(s32, u8, u8, M2C_UNK);        /* extern */
M2C_UNK func_02075540(s32, u8, M2C_UNK);            /* extern */
void *func_02095f90(s32);                           /* extern */
void *func_02095fa8(void *, void *);                /* extern */

void func_02091dc4(void *arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_r0;
    u8 temp_r1;
    u8 temp_r2;
    void *var_r5;

    if (arg1 == 0) {
        return;
    }
    var_r5 = func_02095f90(arg0 + 0x61C);
    if (var_r5 == NULL) {
        return;
    }
    do {
        temp_r2 = M2C_FIELD(var_r5, u8 *, 1);
        temp_r1 = M2C_FIELD(var_r5, u8 *, 0);
        temp_r0 = M2C_FIELD(arg0, s32 *, 0x3C);
        if (temp_r2 != 0xFF) {
            func_02075524(temp_r0, temp_r1, temp_r2, arg2);
        } else {
            func_02075540(temp_r0, temp_r1, arg2);
        }
        var_r5 = func_02095fa8(arg0 + 0x61C, var_r5);
    } while (var_r5 != NULL);
}
