#include "m2c.h"
void func_020506a0(s32 *out, s32 *a, s32 *b) {
    s32 t0, t1, t2;
    s32 *p0, *p1, *p2;
    s32 v0, v1, v2;
    s32 s0, s1, s2;
    if (b[0] >= 0) {
        p0 = &a[10];
    } else {
        t0 = -a[10];
        p0 = &t0;
    }
    v0 = *p0;
    if (b[1] >= 0) {
        p1 = &a[11];
    } else {
        t1 = -a[11];
        p1 = &t1;
    }
    v1 = *p1;
    if (b[2] >= 0) {
        p2 = &a[12];
    } else {
        t2 = -a[12];
        p2 = &t2;
    }
    v2     = *p2;
    s2     = a[3] + v2;
    s1     = a[2] + v1;
    s0     = a[1] + v0;
    out[0] = s0;
    out[1] = s1;
    out[2] = s2;
}
