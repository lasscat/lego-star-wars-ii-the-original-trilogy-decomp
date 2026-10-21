#include "m2c.h"

s32 func_0208c6dc(s32 *arg0, u32 arg1) {
    u32 i;
    s32 t;
    if (arg1 >= 0x10) {
        return 0;
    }
    t = arg1 * 0xb;
    for (i = 0; i < 0xa; i++) {
        if ((arg0[t >> 5] & (1 << (t & 0x1f))) == 0) {
            return 0;
        }
        t++;
    }
    return 1;
}
