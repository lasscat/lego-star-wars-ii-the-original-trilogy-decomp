#include "m2c.h"

void func_0204cb34(s32 *a0, s32 *a1, s32 a2, s32 a3, ...) {
    a0[0]  = a1[0];
    a0[1]  = a1[1];
    a0[2]  = a1[2];
    a0[a2] = *(s32 *) &a3;
}
