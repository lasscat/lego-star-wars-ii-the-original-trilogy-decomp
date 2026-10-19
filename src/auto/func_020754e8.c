#include "m2c.h"
s32 func_020754e8(s32 a0, s32 a1) {
    u32 i;
    s32 v;
    volatile u32 *cnt = (volatile u32 *) (a0 + 4);
    for (i = 0; i < *cnt; i++) {
        s32 *arr = *(s32 *) a0;
        v        = arr[i];
        if (v == a1) {
            return i;
        }
    }
    return 0;
}
