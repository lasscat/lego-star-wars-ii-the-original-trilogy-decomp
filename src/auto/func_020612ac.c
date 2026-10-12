#include "m2c.h"

M2C_UNK func_02062550(s32);                         /* extern */

void func_020612ac(void *arg0) {
    void *var_r4;

    var_r4 = M2C_FIELD(arg0, void **, 4);
    if (var_r4 == NULL) {
        return;
    }
    do {
        func_02062550(M2C_FIELD(var_r4, s32 *, 0));
        var_r4 = M2C_FIELD(var_r4, void **, 4);
    } while (var_r4 != NULL);
}
