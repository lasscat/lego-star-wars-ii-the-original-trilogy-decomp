#include "m2c.h"

void *func_0202c8b4(M2C_UNK, void *, s32, M2C_UNK); /* extern */
s32 func_0202c948(M2C_UNK, s32);                    /* extern */

void func_0202c800(M2C_UNK arg0, void *arg1) {
    u32 temp_r6;
    void *temp_r5;
    void *var_r1;
    void *var_r5;

    temp_r6 = M2C_FIELD(arg1, s32 *, 4);
    var_r1  = func_0202c8b4(arg0, arg1, temp_r6, 0);
    if (var_r1 != NULL) {
        do {
            temp_r5 = var_r1;
            var_r1  = func_0202c8b4(arg0, var_r1, temp_r6, 0);
        } while (var_r1 != NULL);
        func_0202c800(arg0, temp_r5);
        return;
    }
    if (func_0202c948(arg0, temp_r6) == 0) {
        return;
    }
    var_r5 = func_0202c8b4(arg0, arg1, temp_r6, 1);
    if (var_r5 == NULL) {
        return;
    }
    do {
        func_0202c800(arg0, var_r5);
        var_r5 = func_0202c8b4(arg0, var_r5, temp_r6, 1);
    } while (var_r5 != NULL);
}
