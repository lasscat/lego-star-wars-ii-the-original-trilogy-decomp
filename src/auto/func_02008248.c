#include "m2c.h"

void func_0205e84c(s32);

s32 func_02008248(s32 *p) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (p[4 + i] != 0) {
            func_0205e84c(p[4 + i]);
        }
        p[4 + i] = 0;
    }
    return p;
}
