#include "m2c.h"

u8 func_020658c8(void *arg0, u8 *arg1) {
    u8 var_r2;

    var_r2 = 0;
    if (*arg1 != 0) {
        var_r2 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 8);
    }
    return var_r2;
}
