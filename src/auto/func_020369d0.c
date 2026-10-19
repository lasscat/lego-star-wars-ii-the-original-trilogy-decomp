#include "m2c.h"

void *func_020369d0(void *arg0) {
    void **var_r2;
    void *temp_r1;
    void *var_r3;
    void **var_r2_2;
    void *temp_r1_2;
    void *var_r3_2;

    var_r2 = M2C_FIELD(arg0, void ***, 0x18);
    if (var_r2 != NULL) {
        var_r3  = *var_r2;
        temp_r1 = arg0 + 0x18;
        if (var_r3 != temp_r1) {
            do {
                var_r2 = var_r3 + 4;
                var_r3 = M2C_FIELD(var_r3, void **, 4);
            } while (var_r3 != temp_r1);
        }
        *var_r2 = M2C_FIELD(arg0, void **, 0x1C);
    }
    var_r2_2 = M2C_FIELD(arg0, void ***, 0x10);
    if (var_r2_2 == NULL) {
        return arg0;
    }
    var_r3_2  = *var_r2_2;
    temp_r1_2 = arg0 + 0x10;
    if (var_r3_2 != temp_r1_2) {
        do {
            var_r2_2 = var_r3_2 + 4;
            var_r3_2 = M2C_FIELD(var_r3_2, void **, 4);
        } while (var_r3_2 != temp_r1_2);
    }
    *var_r2_2 = M2C_FIELD(arg0, void **, 0x14);
    return arg0;
}
