#include "m2c.h"

M2C_UNK func_0205e84c(s32);                         /* extern */
M2C_UNK func_02063da0(s32);                         /* extern */

void func_02063c18(void *arg0) {
    u32 temp_r5;
    void *var_r4;

    var_r4 = M2C_FIELD(arg0, void **, 4);
    if (var_r4 == NULL) {
        return;
    }
    do {
        temp_r5 = M2C_FIELD(var_r4, s32 *, 0);
        var_r4  = M2C_FIELD(var_r4, void **, 4);
        if (temp_r5 != 0) {
            func_02063da0(temp_r5);
            func_0205e84c(temp_r5);
        }
    } while (var_r4 != NULL);
}
