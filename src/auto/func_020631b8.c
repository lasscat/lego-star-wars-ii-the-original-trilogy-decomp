#include "m2c.h"

M2C_UNK func_020630b8(M2C_UNK);                     /* extern */
s32 func_020633dc(M2C_UNK);                         /* extern */
s32 func_02063418(M2C_UNK);                         /* extern */
s32 func_02063444();                                /* extern */

s32 func_020631b8(M2C_UNK arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    temp_r0_3 = func_02063444();
    if (temp_r0_3 == 0) {
        return temp_r0_3;
    }
    temp_r0_2 = func_02063418(arg0);
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    temp_r0 = func_020633dc(arg0);
    if (temp_r0 == 0) {
        return temp_r0;
    }
    func_020630b8(arg0);
    return temp_r0;
}
