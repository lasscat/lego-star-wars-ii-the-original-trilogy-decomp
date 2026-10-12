#include "m2c.h"

void func_02067b30(void *arg0, s8 arg1, s32 arg2) {
    M2C_FIELD(arg0, s8 *, 4) = arg1;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0) = 0;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0) = arg2;
}
