#include "m2c.h"

void *func_0205afc0(void *, u16 *, s32, void *);    /* extern */

void func_0205af6c(void **arg0, void *arg1, u16 *arg2) {
    void *temp_r0;

    temp_r0 = func_0205afc0(arg1, arg2, M2C_FIELD(arg1, s32 *, 4), arg1 + 4);
    if ((temp_r0 == (arg1 + 4)) || ((u32) *arg2 < (u32) M2C_FIELD(temp_r0, u16 *, 0xC))) {
        *arg0 = arg1 + 4;
        return;
    }
    *arg0 = temp_r0;
}
