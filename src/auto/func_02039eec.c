#include "m2c.h"

s32 func_0201aaec(void);

void func_02039eec(s32 *o, s32 *a, s32 *b) {
    s32 v2, v1, v0;
    v2   = (s32) (((s64) a[0] * b[1] - (s64) a[1] * b[0] + (1 << (func_0201aaec() - 1))) >> func_0201aaec());
    v1   = (s32) (((s64) a[2] * b[0] - (s64) a[0] * b[2] + (1 << (func_0201aaec() - 1))) >> func_0201aaec());
    v0   = (s32) (((s64) a[1] * b[2] - (s64) a[2] * b[1] + (1 << (func_0201aaec() - 1))) >> func_0201aaec());
    o[0] = v0;
    o[1] = v1;
    o[2] = v2;
}
