#include "m2c.h"

s32 func_0205ab30(u16);                             /* extern */

void func_0204c88c(void *arg0, u16 arg1) {
    M2C_FIELD(arg0, u16 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = func_0205ab30(M2C_FIELD(arg0, u16 *, 0));
}
