#include "m2c.h"

void func_02011354(s32 *a0, s32 *a1) {
    s64 sum;
    s64 t;
    t   = (s64) a1[0] * a1[0] + (s64) a1[1] * a1[1];
    sum = t + (s64) a1[2] * a1[2];
    *a0 = (s32) ((sum + 0x800) >> 12);
}
