#include "m2c.h"

M2C_UNK func_0202c354();                      /* extern */
M2C_UNK func_0205d874();                      /* extern */
M2C_UNK func_0205e84c();                      /* extern */
extern M2C_UNK data_020fdc0c;

void *func_0202beb0(void *arg0) {
    void *temp_r0;
    void **temp_r0_2;
    void *temp_r1;
    void **var_r2;
    void *var_r3;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdc0c;
    func_0205e84c(M2C_FIELD(arg0, s32 *, 0x1C));
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    temp_r0                      = M2C_FIELD(arg0, void **, 0x24);
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
    temp_r0_2                      = M2C_FIELD(arg0, void ***, 0x18);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(*temp_r0_2, M2C_UNK(**)(void *), 4)(temp_r0_2);
    }
    M2C_FIELD(arg0, void ***, 0x18) = NULL;
    func_0202c354(arg0);
    func_0205d874(arg0);
    return arg0;
}
