#include "m2c.h"

void *func_0202c710(void *, void *, void *, M2C_UNK); /* extern */

void func_0202c2fc(void *arg0) {
    void *temp_r0;
    void *temp_r2;
    void *var_r5;
    void *var_r6;

    var_r6 = M2C_FIELD(arg0, void **, 4);
    if (var_r6 != NULL) {
        var_r6 -= 4;
    }
    var_r5 = var_r6;
    if (var_r6 == NULL) {
        return;
    }
    do {
        temp_r0                       = func_0202c710(arg0, var_r6, var_r5, 0);
        temp_r2                       = M2C_FIELD(var_r5, void **, 4);
        var_r5                        = temp_r0;
        M2C_FIELD(temp_r2, u8 *, 0xC) = (u8) (M2C_FIELD(temp_r2, u8 *, 0xC) | 1);
    } while (temp_r0 != NULL);
}
