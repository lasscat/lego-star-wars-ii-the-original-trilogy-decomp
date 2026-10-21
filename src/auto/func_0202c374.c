#include "m2c.h"

void *func_0202c710(void *, void *, void *, s32);   /* extern */
void func_0202c374(void *, s32);                   /* extern */

void func_0202c374(void *arg0, s32 arg1) {
    void *temp_r1;
    void *var_r2;
    void *var_r4;
    void *var_r5;

    var_r5 = M2C_FIELD(arg0, void **, 4);
    if (var_r5 != NULL) {
        var_r5 = (void *) ((s8 *) var_r5 - 4);
    }
    var_r4 = var_r5;
    if (var_r5 == NULL) {
        return;
    }
    do {
        var_r2  = var_r4;
        var_r4  = func_0202c710(arg0, var_r5, var_r4, arg1);
        temp_r1 = M2C_FIELD(var_r2, void **, 4);
        if (M2C_FIELD(temp_r1, s32 *, 8) == arg1) {
            M2C_FIELD(temp_r1, u8 *, 0xc) |= 1;
            func_0202c374(arg0, (s32) temp_r1);
        }
    } while (var_r4 != NULL);
}
