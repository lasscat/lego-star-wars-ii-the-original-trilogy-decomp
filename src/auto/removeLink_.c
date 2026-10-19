#include "m2c.h"

s32 removeLink_(void **arg0, void *arg1) {
    void *var_r2;
    void *var_r3;

    var_r3 = *arg0;
    if (var_r3 == NULL) {
        return 0;
    }
    if (var_r3 == arg1) {
        *arg0                        = M2C_FIELD(var_r3, void **, 0x10);
        M2C_FIELD(arg1, s32 *, 0x10) = 0;
        return 1;
    }
    var_r2 = M2C_FIELD(var_r3, void **, 0x10);
    while (var_r2 != NULL) {
        if (var_r2 == arg1) {
            M2C_FIELD(var_r3, void **, 0x10) = (void *) M2C_FIELD(var_r2, void **, 0x10);
            M2C_FIELD(var_r2, void **, 0x10) = NULL;
            return 1;
        }
        var_r3 = var_r2;
        var_r2 = M2C_FIELD(var_r2, void **, 0x10);
    }
    return 0;
}
