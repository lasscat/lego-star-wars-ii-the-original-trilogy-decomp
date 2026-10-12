#include "m2c.h"

void func_020293f8(s32 *arg0, void *arg1) {
    void *temp_r1;

    if (arg1 == NULL) {
        *arg0 = 0;
        return;
    }
    temp_r1 = M2C_FIELD(arg1, void **, 0x20);
    if (temp_r1 == NULL) {
        *arg0 = 0;
        return;
    }
    *arg0 = M2C_FIELD(temp_r1, s32 *, 0x18) * 2;
}
