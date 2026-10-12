#include "m2c.h"

M2C_UNK func_020d3a44();                            /* extern */
s32 func_020d3dc0(M2C_UNK, M2C_UNK *, s32 *);       /* extern */
extern M2C_UNK func_020d3a84;

s32 func_020d3e14(M2C_UNK arg0) {
    s32 sp0;
    s32 temp_r0;

    temp_r0 = func_020d3dc0(arg0, &func_020d3a84, &sp0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020d3a44();
    return sp0;
}
