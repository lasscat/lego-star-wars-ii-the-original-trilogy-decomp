#include "m2c.h"

s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
s32 func_020dca0c();                                /* extern */
s32 func_020dd15c();                                /* extern */
M2C_UNK func_020dd310(M2C_UNK *);                   /* extern */
extern M2C_UNK data_0211e400;
extern M2C_UNK func_020dca44;

s32 func_020dca50(void) {
    s32 temp_r4;
    s32 var_r5;

    var_r5  = 1;
    temp_r4 = func_020ce804();
    if (M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), u16 *, 0x526) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s32 *, 0x5E4) = 0;
        M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), u16 *, 0x526) = 1U;
        if (func_020dd15c() != 0) {
            func_020dd310(&func_020dca44);
            var_r5 = 0;
        } else {
            var_r5 = func_020dca0c();
        }
    }
    func_020ce818(temp_r4);
    return var_r5;
}
