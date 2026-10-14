#include "m2c.h"

M2C_UNK func_020100a4(void *);                      /* extern */
extern M2C_UNK data_020fcfb8;

void *func_02011f64(void *arg0) {
    void **var_r1;
    void **var_r1_2;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *var_r2;
    void *var_r2_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcfb8;
    temp_r1                        = M2C_FIELD(arg0, void **, 0x1C4);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 0x384) = (s32) (M2C_FIELD(temp_r1, s32 *, 0x384) | 0x80000000);
    }
    var_r1 = M2C_FIELD(arg0, void ***, 0x1D0);
    if (var_r1 != NULL) {
        var_r2  = *var_r1;
        temp_r0 = arg0 + 0x1D0;
        if (var_r2 != temp_r0) {
            do {
                var_r1 = var_r2 + 4;
                var_r2 = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0);
        }
        *var_r1 = M2C_FIELD(arg0, void **, 0x1D4);
    }
    var_r1_2 = M2C_FIELD(arg0, void ***, 0x1C8);
    if (var_r1_2 != NULL) {
        var_r2_2  = *var_r1_2;
        temp_r0_2 = arg0 + 0x1C8;
        if (var_r2_2 != temp_r0_2) {
            do {
                var_r1_2 = var_r2_2 + 4;
                var_r2_2 = M2C_FIELD(var_r2_2, void **, 4);
            } while (var_r2_2 != temp_r0_2);
        }
        *var_r1_2 = M2C_FIELD(arg0, void **, 0x1CC);
    }
    func_020100a4(arg0);
    return arg0;
}
