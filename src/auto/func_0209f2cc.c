#include "m2c.h"

M2C_UNK func_0205ab6c(u16);                         /* extern */
s32 func_0205e5e8();                                /* extern */
M2C_UNK func_020c61d4(s32, s32);                    /* extern */

void func_0209f2cc(void *arg0) {
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r4 != 0) {
        func_020c61d4(func_0205e5e8(), temp_r4);
        func_0205ab6c(M2C_FIELD(arg0, u16 *, 4));
        M2C_FIELD(arg0, s32 *, 0) = 0;
    }
    M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) & ~1);
}
