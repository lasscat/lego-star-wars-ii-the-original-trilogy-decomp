#include "m2c.h"

M2C_UNK func_02068154(void *);                      /* extern */
M2C_UNK func_0206818c();                            /* extern */

void func_020680fc(void *arg0) {
    s32 temp_r1;

    if (M2C_FIELD(arg0, u8 *, 1) == 0) {
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r1 != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_r1 - 1);
        return;
    }
    func_0206818c(arg0);
    func_02068154(arg0);
}
