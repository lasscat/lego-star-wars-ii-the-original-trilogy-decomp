#include "m2c.h"

M2C_UNK func_02028f04();                            /* extern */
M2C_UNK func_020b973c();                            /* extern */

void *func_0202897c(void *arg0) {
    void **var_r1;
    void *temp_r0;
    void *var_r2;

    func_02028f04();
    if (M2C_FIELD(arg0, s32 *, 0x18) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x18) = 0;
    }
    var_r1 = M2C_FIELD(arg0, void ***, 8);
    if (var_r1 != NULL) {
        var_r2 = *var_r1;
        temp_r0 = arg0 + 8;
        if (var_r2 != temp_r0) {
            do {
                var_r1 = var_r2 + 4;
                var_r2 = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0);
        }
        *var_r1 = M2C_FIELD(arg0, void **, 0xC);
    }
    return arg0;
}
