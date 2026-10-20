#include "m2c.h"

void func_020b973c(void *); /* extern */

void func_0202fa64(void *arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x2c);
    if (temp_r0 != NULL) {
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 8) & 0x802) {
            func_020b973c(temp_r0);
            M2C_FIELD(arg0, void **, 0x2c) = NULL;
        } else {
            M2C_FIELD(temp_r0, u8 *, 0x1a) |= 1;
        }
    }
}
