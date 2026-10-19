#include "m2c.h"
s32 func_0205de84(s32 a0, s32 a1) {
    s32 p   = *(s32 *) (a0 + 4);
    s32 ret = 0;
    s32 q;
    if (p == 0) {
        return 0;
    }
    for (;;) {
        q = a1;
        if (q != 0) {
            q = q + 4;
        }
        if (p == q) {
            ret = 1;
            break;
        }
        p = *(s32 *) (p + 4);
        if (p == 0) {
            break;
        }
    }
    return ret;
}
