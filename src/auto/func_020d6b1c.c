#include "m2c.h"

s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
void *func_020d65a4();                              /* extern */
s32 func_020d65b4();                                /* extern */

s32 func_020d6b1c(s32 arg0) {
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = func_020ce804();
    temp_r0 = func_020d65b4();
    if (temp_r0 != 0) {
        func_020ce818(temp_r5);
        return temp_r0;
    }
    M2C_FIELD(func_020d65a4(), s32 *, 0xC8) = arg0;
    func_020ce818(temp_r5);
    return 0;
}
