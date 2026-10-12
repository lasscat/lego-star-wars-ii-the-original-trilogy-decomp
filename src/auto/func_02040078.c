#include "m2c.h"

M2C_UNK func_0202897c(s32);                         /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */

s32 *func_02040078(s32 *arg0) {
    s32 temp_r4;

    temp_r4 = *arg0;
    if (temp_r4 != 0) {
        func_0202897c(temp_r4);
        func_0205e84c(temp_r4);
    }
    return arg0;
}
