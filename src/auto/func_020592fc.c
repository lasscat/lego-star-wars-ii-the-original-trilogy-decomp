#include "m2c.h"

M2C_UNK func_02035c2c(s32, u8, M2C_UNK, M2C_UNK);   /* extern */
void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_020592fc(M2C_UNK arg0, void *arg1) {
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 != NULL) {
        temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x5F8);
        if (temp_r0_2 != 0) {
            func_02035c2c(temp_r0_2, M2C_FIELD(arg1, u8 *, 2), 0, 1);
        }
    }
}
