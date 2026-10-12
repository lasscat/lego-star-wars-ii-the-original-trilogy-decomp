#include "m2c.h"

M2C_UNK func_0202c0cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202c118(void *, s32, M2C_UNK, M2C_UNK); /* extern */
s32 func_0202f784(s32, M2C_UNK);                    /* extern */

s32 func_0202c1d4(void *arg0, M2C_UNK arg1) {
    s32 temp_r0;

    func_0202c0cc(arg0, 0);
    temp_r0 = func_0202f784(M2C_FIELD(arg0, s32 *, 0x20), arg1);
    if (temp_r0 != 0) {
        func_0202c118(arg0, temp_r0, 0, 0);
    }
    return temp_r0;
}
