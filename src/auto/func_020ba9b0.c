#include "m2c.h"

M2C_UNK func_0205e5b0(s32);                         /* extern */

void func_020ba9b0(void *arg0) {
    s8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s8 *, 6);
    if (temp_r1 != -1) {
        M2C_FIELD(arg0, s8 *, 6) = (s8) (temp_r1 - 1);
        if (M2C_FIELD(arg0, s8 *, 6) != 0) {
            return;
        }
    }
    func_0205e5b0(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0) = 0;
}
