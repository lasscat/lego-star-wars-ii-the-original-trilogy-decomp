#include "m2c.h"

void func_0205ea38(s32 arg0, s32 arg1) {
    u32 i;
    for (i = 0; i < *(u16 *) ((s8 *) arg0 + 4); i++) {
        s32 *arr = *(s32 **) arg0;
        s32 *p   = arr[i];
        u32 v;
        if (p == 0) {
            continue;
        }
        v = *(u32 *) ((s8 *) p + 8);
        if (arg1 != 0) {
            v |= 1;
            *(u32 *) ((s8 *) p + 8) = v;
        } else {
            v &= ~1u;
            *(u32 *) ((s8 *) p + 8) = v;
        }
    }
}
