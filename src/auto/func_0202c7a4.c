#include "m2c.h"
#include "engine.h"

s32 func_0202c7a4(s32 arg0, s32 arg1, s32 arg2) {
    void *var_r2;
    void *var_r3;

    if (arg2 == arg1) {
        return 0;
    }
    var_r2 = M2C_FIELD(arg2, void **, 0xC);
    if (var_r2 != NULL) {
        var_r2 -= 4;
    }
    if (var_r2 == NULL) {
        return 0;
    }
    if (M2C_FIELD(var_r2, s32 *, 0x10) != 0) {
        return (s32) var_r2;
    }
    var_r3 = M2C_FIELD(var_r2, void **, 0x14);
    if (var_r3 != NULL) {
        do {
            var_r2 = var_r3;
            var_r3 = M2C_FIELD(var_r3, void **, 0x14);
        } while (var_r3 != NULL);
    }
    return func_0202c7a4(arg0, arg1, (s32) var_r2);
}
