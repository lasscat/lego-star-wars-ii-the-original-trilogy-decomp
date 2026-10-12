#include "m2c.h"

s32 func_0205d66c(void *, void *);                  /* extern */

void func_0205d9a8(void *arg0, void *arg1, void *arg2) {
    void *var_r0;
    void *var_r1;
    void *var_r4;

    var_r4 = arg2;
    if (var_r4 == NULL) {
        var_r4 = M2C_FIELD(arg0, void **, 8);
        if (var_r4 != NULL) {
            var_r4 -= 4;
        }
    }
    var_r1 = arg1;
    if (arg1 != NULL) {
        var_r1 = arg1 + 4;
    }
    if (func_0205d66c(arg0, var_r1) != 0) {
        return;
    }
    var_r0 = M2C_FIELD(var_r4, void **, 0x10);
    if (var_r0 != NULL) {
        do {
            var_r4 = var_r0;
            var_r0 = M2C_FIELD(var_r0, void **, 0x10);
        } while (var_r0 != NULL);
    }
    M2C_FIELD(var_r4, void **, 0x10) = arg1;
    M2C_FIELD(arg1, void **, 0x14) = var_r4;
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0xC) = 0;
}
