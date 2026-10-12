#include "m2c.h"

void func_0205d8bc(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 var_r2;

    var_r2 = M2C_FIELD(arg0, s32 *, 8);
    if (var_r2 != 0) {
        var_r2 -= 4;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(void *, M2C_UNK, s32, M2C_UNK), 0x38)(arg0, arg1, var_r2, arg2);
}
