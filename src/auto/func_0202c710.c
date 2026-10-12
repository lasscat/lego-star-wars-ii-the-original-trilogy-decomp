#include "m2c.h"

void *func_0202c7a4();                              /* extern */

void *func_0202c710(M2C_UNK arg0, M2C_UNK arg1, void *arg2, s32 arg3) {
    s32 var_ip;
    void *temp_r0;
    void *var_r2;
    void *var_r3;

    var_r2 = arg2;
    var_ip = 0;
    if (var_r2 == NULL) {
        return var_r2;
    }
    if ((M2C_FIELD(var_r2, s32 *, 0x10) == 0) && (M2C_FIELD(var_r2, s32 *, 8) == 0)) {
        temp_r0 = func_0202c7a4(arg0, arg1);
        var_r2 = temp_r0;
        var_ip = 1;
        if (var_r2 == NULL) {
            return temp_r0;
        }
        goto block_8;
    }
block_8:
    if (var_ip != 0) {
        var_r3 = M2C_FIELD(var_r2, void **, 0x10);
    } else {
        var_r3 = M2C_FIELD(var_r2, void **, 8);
        if (var_r3 != NULL) {
            var_r3 -= 4;
        }
        if (var_r3 == NULL) {
            var_r3 = M2C_FIELD(var_r2, void **, 0x10);
        }
    }
    if ((arg3 != 0) && (M2C_FIELD(M2C_FIELD(var_r3, void **, 4), s32 *, 8) != arg3)) {
        return func_0202c710(arg0, arg1, var_r3, arg3);
    }
    return var_r3;
}
