#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020e47fc(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK data_020fe21c;
extern M2C_UNK func_02040078;

void *func_02041f78(void *arg0) {
    void **var_r1;
    void *temp_r0;
    void *temp_r5;
    void *var_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe21c;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x690) = 0;
    temp_r5 = M2C_FIELD(arg0, void **, 0x10);
    if (temp_r5 != NULL) {
        var_r1 = M2C_FIELD(temp_r5, void ***, 0x28);
        if (var_r1 != NULL) {
            var_r2 = *var_r1;
            temp_r0 = temp_r5 + 0x28;
            if (var_r2 != temp_r0) {
                do {
                    var_r1 = var_r2 + 4;
                    var_r2 = M2C_FIELD(var_r2, void **, 4);
                } while (var_r2 != temp_r0);
            }
            *var_r1 = M2C_FIELD(temp_r5, void **, 0x2C);
        }
        func_020e47fc(temp_r5 + 0x1C, 2, 4, &func_02040078);
        func_0205e84c(temp_r5);
    }
    func_0205e84c(arg0);
    return arg0;
}
