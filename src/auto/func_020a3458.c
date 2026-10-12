#include "m2c.h"

M2C_UNK func_0205d4c8(void *);                      /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */

void func_020a3458(void *arg0, s8 arg1) {
    void *temp_r4;
    void *temp_r5;
    void *var_r1;

    M2C_FIELD(arg0, s8 *, 0x23F) = arg1;
    var_r1 = M2C_FIELD(arg0, void **, 0x398);
    if (var_r1 == NULL) {
        return;
    }
    do {
        temp_r4 = M2C_FIELD(var_r1, void **, 0);
        if ((temp_r4 != NULL) && (M2C_FIELD(temp_r4, s32 *, 0x24) == 4)) {
            temp_r5 = M2C_FIELD(var_r1, void **, 8);
            func_0205d4c8(arg0 + 0x394);
            func_0205e84c(temp_r4);
            if (temp_r5 != NULL) {
                var_r1 = M2C_FIELD(temp_r5, void **, 4);
            } else {
                var_r1 = M2C_FIELD(arg0, void **, 0x398);
            }
        } else {
            var_r1 = M2C_FIELD(var_r1, void **, 4);
        }
    } while (var_r1 != NULL);
}
