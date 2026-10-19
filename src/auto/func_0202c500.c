#include "m2c.h"

void *func_0202ceec(void *, s32);                   /* extern */
M2C_UNK func_0202cf2c(void *);                      /* extern */
void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */

void func_0202c500(void *arg0, s32 arg1) {
    void *temp_r1;
    void **var_r2;
    void *var_r3;
    void *var_r0;
    void *temp_r0;

    if (arg1 == 7) {
        temp_r0 = M2C_FIELD(arg0, void **, 0x24);
        if (temp_r0 != NULL) {
            var_r2 = M2C_FIELD(temp_r0, void ***, 0xC);
            if (var_r2 != NULL) {
                var_r3  = *var_r2;
                temp_r1 = temp_r0 + 0xC;
                if (var_r3 != temp_r1) {
                    do {
                        var_r2 = var_r3 + 4;
                        var_r3 = M2C_FIELD(var_r3, void **, 4);
                    } while (var_r3 != temp_r1);
                }
                *var_r2 = M2C_FIELD(temp_r0, void **, 0x10);
            }
            func_0205e84c(temp_r0);
        }
        M2C_FIELD(arg0, void **, 0x24) = NULL;
        return;
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x24);
    if (temp_r0 != NULL) {
        func_0202cf2c(temp_r0);
        return;
    }
    var_r0 = func_0205e80c(0x14, 1, 4);
    if (var_r0 != NULL) {
        var_r0 = func_0202ceec(var_r0, arg1);
    }
    M2C_FIELD(arg0, void **, 0x24) = var_r0;
}
