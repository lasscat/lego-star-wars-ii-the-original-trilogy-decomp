#include "m2c.h"
void func_0207a744(s32 a0) {
    s32 i;
    for (i = 0; i < 0x14; i++) {
        s32 *p = ((s32 *) a0)[0x37 + i];
        p[2] &= ~1;
    }
}
