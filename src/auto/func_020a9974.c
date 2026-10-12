#include "m2c.h"

void func_020a9974(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    s8 var_r1;

    M2C_FIELD(arg0, s8 *, 0x2E0) = arg1;
    M2C_FIELD(arg0, s8 *, 0x2E1) = arg2;
    M2C_FIELD(arg0, s8 *, 0x2E2) = arg1;
    if ((u32) arg1 <= (u32) arg2) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    M2C_FIELD(arg0, s8 *, 0x2E8) = var_r1;
    M2C_FIELD(arg0, s8 *, 0x23C) = 0;
    M2C_FIELD(arg0, s8 *, 0x23E) = 3;
    M2C_FIELD(arg0, s8 *, 0x2E9) = arg3;
}
