#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *);                   /* extern */
M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
M2C_UNK func_020addf0(M2C_UNK);                     /* extern */
s32 func_020d71c8(M2C_UNK *);                       /* extern */
extern M2C_UNK data_02100094;
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020aeea8;

s32 func_020add78(void) {
    s32 temp_r0;
    s32 var_r0;

    func_020ad528(&data_02100094);
    func_020ad7a4(3);
    temp_r0 = func_020d71c8(&func_020aeea8);
    if (temp_r0 == 0) {
        return 1;
    }
    if (temp_r0 == 2) {
        func_020addf0(9);
        if (M2C_FIELD(&data_0210b320, s32 *, 0x30) == 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 0;
}
