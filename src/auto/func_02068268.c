#include "m2c.h"

s32 func_020b8f70(u16, M2C_UNK);                    /* extern */
M2C_UNK func_020b9068(s32);                         /* extern */
s32 func_020b9304(s32);                             /* extern */

void func_02068268(void *arg0, u16 arg1) {
    if (arg1 == 0xC9) {
        func_020b9068(M2C_FIELD(arg0, s32 *, 0xC));
        M2C_FIELD(arg0, s32 *, 0xC) = -1;
    } else if ((M2C_FIELD(arg0, u16 *, 8) != arg1) || (func_020b9304(M2C_FIELD(arg0, s32 *, 0xC)) == 0)) {
        M2C_FIELD(arg0, s32 *, 0xC) = func_020b8f70(arg1, 0);
    }
    M2C_FIELD(arg0, u16 *, 8) = arg1;
}
