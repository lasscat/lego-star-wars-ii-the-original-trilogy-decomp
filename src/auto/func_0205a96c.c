#include "m2c.h"

s32 func_0205e818(s32, M2C_UNK, M2C_UNK);           /* extern */

void *func_0205a96c(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s8 *, 0)  = 0;
    M2C_FIELD(arg0, s16 *, 2) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = func_0205e818(arg1 * 2, 3, 4);
    return arg0;
}
