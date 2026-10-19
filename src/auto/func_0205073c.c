#include "m2c.h"

void func_0205073c(void *arg0, void *arg1) {
    s32 *p = arg0;
    s32 *q = arg1;
    s32 t;

    q[0] = (p[1] - p[0xA]) - p[0xC];
    t    = p[1] + p[0xA];
    q[1] = t + p[0xC];
    q[2] = p[2] - p[0xB];
    q[3] = p[2] + p[0xB];
    q[4] = (p[3] - p[0xC]) - p[0xA];
    t    = p[3] + p[0xC];
    q[5] = t + p[0xA];
}
