#include "m2c.h"

void func_0205bcbc(void *arg0, void **arg1) {
    s32 temp_r3_2;
    void *temp_r2;
    void *temp_r3;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    if (*arg1 == arg0) {
        *arg1 = temp_r2;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) M2C_FIELD(temp_r2, void **, 0);
    temp_r3                     = M2C_FIELD(temp_r2, void **, 0);
    if (temp_r3 != NULL) {
        M2C_FIELD(temp_r3, s32 *, 8) = (s32) ((s32) arg0 | (M2C_FIELD(temp_r3, s32 *, 8) & 1));
    }
    M2C_FIELD(temp_r2, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s32 *, 8) & ~1) | (M2C_FIELD(temp_r2, s32 *, 8) & 1));
    temp_r3_2                    = M2C_FIELD(arg0, s32 *, 8) & ~1;
    if (arg0 == M2C_FIELD(temp_r3_2, void **, 0)) {
        M2C_FIELD(temp_r3_2, void **, 0) = temp_r2;
    } else {
        M2C_FIELD(temp_r3_2, void **, 4) = temp_r2;
    }
    M2C_FIELD(temp_r2, void **, 0) = arg0;
    M2C_FIELD(arg0, s32 *, 8)      = (s32) ((s32) temp_r2 | (M2C_FIELD(arg0, s32 *, 8) & 1));
}
