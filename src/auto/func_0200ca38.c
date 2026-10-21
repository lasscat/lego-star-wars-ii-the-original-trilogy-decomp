#include "m2c.h"

void func_0200ca38(s32 a0) {
    u32 i;
    u8 *p = (u8 *) a0;
    for (i = 0; i < 12; i++) {
        s8 v;
        p[0x1df] = 0;
        v        = *(s8 *) (p + 0x1e1);
        if (v != -1) {
            ((u8 *) a0)[v * 0x38 + 0x3cd] = 0;
        }
        p += 0x28;
    }
}
