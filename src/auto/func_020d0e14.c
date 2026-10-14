#include "engine.h"
#include "m2c.h"

M2C_UNK func_020ce804(void);
void func_020ce818(M2C_UNK);

extern M2C_UNK data_02115800;

s32 func_020d0e14(void) {
    M2C_UNK *var_r1;
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = func_020ce804();
    var_r4  = 0;
    var_r1  = M2C_FIELD(&data_02115800, M2C_UNK **, 8);
    if (var_r1 != NULL) {
        do {
            var_r1 = *var_r1;
            var_r4 += 1;
        } while (var_r1 != NULL);
    }
    func_020ce818(temp_r0);
    return var_r4;
}
