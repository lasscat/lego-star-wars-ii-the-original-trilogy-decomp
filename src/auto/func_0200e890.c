#include "m2c.h"

M2C_UNK func_0200e8f0(void *, s32);                 /* extern */
s32 func_0200ea7c(void *);                          /* extern */
s32 func_0204a880(void *);                          /* extern */
M2C_UNK func_02075c14(s32, void *, M2C_UNK);        /* extern */

void func_0200e890(void *arg0, M2C_UNK arg1) {
    s32 temp_r4;

    func_02075c14(arg0 + 0x6F8, arg0, arg1);
    if ((M2C_FIELD(arg0, s32 *, 8) & 1) != 1) {
        return;
    }
    temp_r4 = func_0200ea7c(arg0);
    if (func_0204a880(arg0 + 0x5CE) == 0) {
        M2C_FIELD(arg0, s32 *, 0x6AC) = temp_r4;
        return;
    }
    func_0200e8f0(arg0, temp_r4);
}
