#include "m2c.h"

extern void func_0205e84c(s32 a0);

s32 *func_0205c9ac(s32 *a0) {
    u32 i;
    s32 zero = 0;
    for (i = 0; i < 5; i++) {
        if (a0[i] != 0) {
            func_0205e84c(a0[i]);
        }
        a0[i] = zero;
    }
    return a0;
}
