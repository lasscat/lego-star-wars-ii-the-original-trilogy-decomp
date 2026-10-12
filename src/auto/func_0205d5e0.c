#include "m2c.h"

s32 func_0205d66c();                                /* extern */

void func_0205d5e0(void *arg0, void *arg1) {
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 4);
    if (func_0205d66c() != 0) {
        return;
    }
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, void **, 4) = temp_r4;
    M2C_FIELD(temp_r4, void **, 8) = arg1;
    M2C_FIELD(arg0, void **, 4) = arg1;
}
