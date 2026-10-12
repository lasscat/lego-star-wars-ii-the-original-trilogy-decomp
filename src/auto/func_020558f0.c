#include "m2c.h"

void *func_0205e018();                       /* extern */

void func_020558f0(M2C_UNK arg0, void *arg1, void **arg2) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r1;

    temp_r0 = func_0205e018();
    M2C_FIELD(temp_r0, void **, 0) = arg1;
    M2C_FIELD(temp_r0, void **, 4) = (void *) *arg2;
    M2C_FIELD(temp_r0, s32 *, 8) = (s32) ((s32) arg2 | 0x80000000);
    temp_r0_2 = *arg2;
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, void **, 8) = temp_r0;
    }
    *arg2 = temp_r0;
    temp_r0_3 = func_0205e018(arg0);
    M2C_FIELD(temp_r0_3, void **, 0) = temp_r0;
    M2C_FIELD(temp_r0_3, void **, 4) = (void *) M2C_FIELD(arg1, void **, 0x28);
    temp_r1 = M2C_FIELD(arg1, void **, 0x28);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, void **, 8) = temp_r0_3;
    }
    M2C_FIELD(arg1, void **, 0x28) = temp_r0_3;
}
