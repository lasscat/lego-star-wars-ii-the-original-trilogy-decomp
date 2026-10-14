#include "m2c.h"

M2C_UNK func_0200c848(void *, M2C_UNK);             /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
extern M2C_UNK data_020fe2d0;

void *func_02045440(void *arg0) {
    u8 temp_r1;
    void **var_r1;
    void *temp_r0;
    void *temp_r0_2;
    void *var_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe2d0;
    temp_r0                        = M2C_FIELD(arg0, void **, 4);
    temp_r1                        = M2C_FIELD(temp_r0, u8 *, 0x6C4);
    if ((temp_r1 & 4) || (!(temp_r1 & 1) && !(temp_r1 & 2))) {
        func_0200c848(temp_r0, 5);
        func_0200c848(M2C_FIELD(arg0, void **, 4), 4);
    }
    var_r1 = M2C_FIELD(arg0, void ***, 0x14);
    if (var_r1 != NULL) {
        var_r2    = *var_r1;
        temp_r0_2 = arg0 + 0x14;
        if (var_r2 != temp_r0_2) {
            do {
                var_r1 = var_r2 + 4;
                var_r2 = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0_2);
        }
        *var_r1 = M2C_FIELD(arg0, void **, 0x18);
    }
    func_0205e84c(arg0);
    return arg0;
}
