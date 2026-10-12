#include "m2c.h"

M2C_UNK func_02018658(s32);                         /* extern */

void func_020184b0(void *arg0) {
    void *temp_r4;
    void *var_r0;

    var_r0 = M2C_FIELD(arg0, void **, 4);
    if (var_r0 == NULL) {
        return;
    }
    do {
        temp_r4 = M2C_FIELD(var_r0, void **, 4);
        func_02018658(M2C_FIELD(var_r0, s32 *, 0));
        var_r0 = temp_r4;
    } while (temp_r4 != NULL);
}
