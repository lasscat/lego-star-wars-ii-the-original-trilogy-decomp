#include "m2c.h"
s32 func_02083358(u8 *p, s32 v) {
    s32 i;
    s32 n;
    if (v == 0x26 || v >= 0x28 || v == 0x27) {
        return -1;
    }
    n = *(s32 *) ((u8 *) p + 0x160);
    i = 0;
    while (i < n && *(u8 *) (*(u32 *) ((u8 *) p + 0x15c) + i) != v) {
        i++;
    }
    if (i >= n) {
        return -1;
    }
    return i;
}
