#include "m2c.h"

s32 func_0202cb44(void *arg0) {
    s32 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x24);
    if (temp_r0 != NULL) {
        var_r0 = M2C_FIELD(temp_r0, s32 *, 0xC);
        if (var_r0 != 0) {
            var_r0 -= 4;
        }
        return var_r0;
    }
    return 0;
}
