#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */

void *func_0203afac(void *arg0) {
    void **var_r1;
    void *temp_r0;
    void *var_r2;

    var_r1 = M2C_FIELD(arg0, void ***, 0x10);
    if (var_r1 != NULL) {
        var_r2 = *var_r1;
        temp_r0 = arg0 + 0x10;
        if (var_r2 != temp_r0) {
            do {
                var_r1 = var_r2 + 4;
                var_r2 = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0);
        }
        *var_r1 = M2C_FIELD(arg0, void **, 0x14);
    }
    func_0205e84c(arg0);
    return arg0;
}
