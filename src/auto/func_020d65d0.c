#include "m2c.h"

M2C_UNK func_020cdd00(u16 *, M2C_UNK);              /* extern */
s32 func_020d65b4();                                /* extern */
extern M2C_UNK data_02117e20;

s32 func_020d65d0(void) {
    s32 temp_r0;

    temp_r0 = func_020d65b4();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020cdd00(M2C_FIELD(M2C_FIELD(&data_02117e20, void **, 4), u16 **, 4), 2);
    if ((u32) *M2C_FIELD(M2C_FIELD(&data_02117e20, void **, 4), u16 **, 4) <= 1U) {
        return 3;
    }
    return 0;
}
