#include "m2c.h"

void func_0205e310(void *arg0, void *arg1) {
    void *var_r1;

    var_r1                        = arg1;
    M2C_FIELD(var_r1, void **, 8) = (void *) M2C_FIELD(arg0, void **, 0x18);
    if (var_r1 != NULL) {
        var_r1 += 4;
    }
    M2C_FIELD(arg0, void **, 0x18) = var_r1;
    M2C_FIELD(arg0, u16 *, 0x1E)   = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + 1);
}
