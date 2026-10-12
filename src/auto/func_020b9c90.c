#include "m2c.h"

M2C_UNK func_020b9768(s32);                         /* extern */
M2C_UNK func_020b9ab0();                            /* extern */

void func_020b9c90(void *arg0) {
    void *temp_r4;
    void *var_r0;

    func_020b9ab0();
    var_r0 = M2C_FIELD(arg0, void **, 4);
    if (var_r0 == NULL) {
        return;
    }
    do {
        temp_r4 = M2C_FIELD(var_r0, void **, 4);
        func_020b9768(M2C_FIELD(var_r0, s32 *, 0));
        var_r0 = temp_r4;
    } while (temp_r4 != NULL);
}
