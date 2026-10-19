#include "m2c.h"

void func_02021110(void *arg0, void **arg1) {
    void **var_r1;
    void **var_r3;
    void *temp_r2;
    void *var_ip;

    var_r1 = arg1;
    if (M2C_FIELD(arg0, u8 *, 0x1BC) != 0) {
        return;
    }
    var_r3 = M2C_FIELD(arg0, void ***, 0x1D0);
    if (var_r1 != NULL) {
        var_r1 += 1;
    }
    if (var_r3 != NULL) {
        var_ip  = *var_r3;
        temp_r2 = arg0 + 0x1D0;
        if (var_ip != temp_r2) {
            do {
                var_r3 = var_ip + 4;
                var_ip = M2C_FIELD(var_ip, void **, 4);
            } while (var_ip != temp_r2);
        }
        *var_r3 = M2C_FIELD(arg0, void **, 0x1D4);
    }
    if (var_r1 != NULL) {
        M2C_FIELD(arg0, void ***, 0x1D0) = var_r1;
        M2C_FIELD(arg0, void **, 0x1D4)  = (void *) *var_r1;
        *var_r1                          = arg0 + 0x1D0;
    } else {
        M2C_FIELD(arg0, void ***, 0x1D0) = NULL;
        M2C_FIELD(arg0, void **, 0x1D4)  = NULL;
    }
    M2C_FIELD(arg0, u8 *, 0x1BC) = 1U;
}
