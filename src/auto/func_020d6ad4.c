#include "m2c.h"

M2C_UNK func_020cdd00(s32, M2C_UNK);                /* extern */
s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
extern M2C_UNK data_02117e20;

u16 func_020d6ad4(void) {
    void *temp_r4;
    u16 var_r4;
    s32 temp_r5;

    temp_r5 = func_020ce804();
    if (M2C_FIELD(&data_02117e20, void **, 4) == NULL) {
        var_r4 = 0;
    } else {
        temp_r4 = M2C_FIELD(M2C_FIELD(&data_02117e20, void **, 4), void **, 4);
        func_020cdd00(temp_r4 + 0x86, 2);
        var_r4 = M2C_FIELD(temp_r4, u16 *, 0x86);
    }
    func_020ce818(temp_r5);
    return var_r4;
}
