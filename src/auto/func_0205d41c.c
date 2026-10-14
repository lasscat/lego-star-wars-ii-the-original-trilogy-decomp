#include "m2c.h"

M2C_UNK func_0205d57c(void *, s32 *, M2C_UNK);      /* extern */
s32 *func_0205e018(s32);                            /* extern */

void func_0205d41c(void *arg0, s32 arg1) {
    s32 *temp_r0;

    temp_r0  = func_0205e018(M2C_FIELD(arg0, s32 *, 0x10));
    *temp_r0 = arg1;
    func_0205d57c(arg0, temp_r0, 0);
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) (M2C_FIELD(arg0, u16 *, 0xC) + 1);
}
