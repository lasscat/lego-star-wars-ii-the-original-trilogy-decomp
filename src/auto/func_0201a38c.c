#include "m2c.h"

s16 func_0205a398(s32);                             /* extern */

void func_0201a38c(void *arg0, s16 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0xD4) == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 8)    = (s32) (M2C_FIELD(arg0, s32 *, 8) | 8);
    M2C_FIELD(arg0, s16 *, 0xEC) = arg1;
    M2C_FIELD(arg0, s16 *, 0xEE) = func_0205a398(M2C_FIELD(arg0, s32 *, 0xD4));
    M2C_FIELD(arg0, s16 *, 0xF0) = 0;
    M2C_FIELD(arg0, s16 *, 0xF2) = 0;
}
