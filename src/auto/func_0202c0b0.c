#include "m2c.h"

s32 func_0202c0b0(void *arg0) {
    void *var_r0;

    var_r0 = M2C_FIELD(arg0, void **, 8);
    if (var_r0 != NULL) {
        var_r0 -= 4;
    }
    if (var_r0 != NULL) {
        return M2C_FIELD(var_r0, s32 *, 4);
    }
    return 0;
}
