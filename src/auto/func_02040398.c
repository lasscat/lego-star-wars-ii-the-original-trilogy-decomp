#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020e47fc(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK data_020fe1ec;
extern M2C_UNK func_02040078;

void *func_02040398(void *arg0) {
    void **var_r1;
    void **var_r1_2;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r4;
    void *var_r2;
    void *var_r2_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe1ec;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x690) = 0;
    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    if (temp_r4 != NULL) {
        var_r1 = M2C_FIELD(temp_r4, void ***, 0x6C);
        if (var_r1 != NULL) {
            var_r2 = *var_r1;
            temp_r0 = temp_r4 + 0x6C;
            if (var_r2 != temp_r0) {
                do {
                    var_r1 = var_r2 + 4;
                    var_r2 = M2C_FIELD(var_r2, void **, 4);
                } while (var_r2 != temp_r0);
            }
            *var_r1 = M2C_FIELD(temp_r4, void **, 0x70);
        }
        var_r1_2 = M2C_FIELD(temp_r4, void ***, 0x5C);
        if (var_r1_2 != NULL) {
            var_r2_2 = *var_r1_2;
            temp_r0_2 = temp_r4 + 0x5C;
            if (var_r2_2 != temp_r0_2) {
                do {
                    var_r1_2 = var_r2_2 + 4;
                    var_r2_2 = M2C_FIELD(var_r2_2, void **, 4);
                } while (var_r2_2 != temp_r0_2);
            }
            *var_r1_2 = M2C_FIELD(temp_r4, void **, 0x60);
        }
        func_020e47fc(temp_r4 + 0x50, 2, 4, &func_02040078);
        func_0205e84c(temp_r4);
    }
    func_0205e84c(arg0);
    return arg0;
}
