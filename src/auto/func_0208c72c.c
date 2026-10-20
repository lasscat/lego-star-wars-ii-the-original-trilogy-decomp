#include "m2c.h"

s32 func_0208c72c(s32 *arg0, u32 arg1) {
    s32 n;
    u32 i;
    s32 t;
    if (arg1 >= 0x10) {
        return 0;
    }
    t = arg1 * 0xb;
    n = 0;
    for (i = 0; i < 0xa; i++) {
        if (arg0[t >> 5] & (1 << (t & 0x1f))) {
            n++;
        }
        t++;
    }
    return n;
}
