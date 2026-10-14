#include "engine.h"
#include "m2c.h"

M2C_UNK func_020ce804(void);
void func_020ce818(M2C_UNK);

extern M2C_UNK data_02115800;

s32 func_020d0d5c(void) {
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = func_020ce804();
    if (M2C_FIELD(&data_02115800, s32 *, 8) == 0) {
        var_r4 = M2C_FIELD(&data_02115800, s32 *, 4);
    } else {
        var_r4 = M2C_FIELD(&data_02115800, s32 *, 0x20);
    }
    func_020ce818(temp_r0);
    return var_r4;
}
