#include "m2c.h"

s32 func_020c3e84(s32, s32);
s32 func_020c3fc4(s32, s32);

s32 func_020c4070(s32 a0, s32 a1) {
    u8 *p = (u8 *) a0;
    u8 *table;
    u32 i;
    s32 result;

    result = 1;
    i      = 0;
    if (i < p[9]) {
        table = p + 8;
        do {
            u32 idx    = *(u16 *) (p + 0xe);
            u32 stride = *(u16 *) (table + idx);
            u32 off    = *(u32 *) (table + idx + stride * i + 4);
            result &= func_020c3e84(a0 + off, a1);
            result &= func_020c3fc4(a0 + off, a1);
            i++;
        } while (i < p[9]);
    }
    return result;
}
