#include "m2c.h"

s32 func_0205a348(s32 arg0) {
    u32 v = *(u16 *) ((s8 *) arg0 + 4) * *(u16 *) ((s8 *) arg0 + 6);
    switch (*(u32 *) ((s8 *) arg0 + 0xc)) {
        case 0:
        case 1:
            break;
        case 2:
            v >>= 1;
        case 3:
            v >>= 1;
            break;
        case 4:
        case 5:
        case 6:
            break;
        case 7:
            v <<= 1;
            break;
    }
    return v;
}
