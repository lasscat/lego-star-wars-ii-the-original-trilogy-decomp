/* Reconstructed from USA ARM9 at 0x0208db80 (200 bytes). */
#include "m2c.h"

s32 func_02062a7c(s32 arg0, s32 arg1);             /* extern */
s32 func_02062b3c(u32 arg0);                       /* extern */
s32 func_0208dad8(s32 arg0);                       /* extern */

s32 func_0208db80(u32 arg0) {
    s32 hi;
    s32 lo;
    s32 res;
    u16 i;

    switch (arg0) {
        case 0:
            lo = 0;
            hi = 0x2c;
            break;
        case 1:
            lo = 0x2d;
            hi = 0x6a;
            break;
        case 2:
            lo = 0x6b;
            hi = 0xb0;
            break;
        case 3:
            lo = 0xb1;
            hi = 0xe7;
            break;
        case 4:
            lo = 0xe8;
            hi = 0xf9;
            if (func_02062b3c(0x3c)) {
                return 0xfa;
            }
            break;
        default:
            return 0;
    }

    for (i = 0; i <= 5; i++) {
        res = (u16) func_02062a7c(lo, hi);
        if (M2C_FIELD(func_0208dad8(res), u8 *, 0x18) != 0) {
            goto done;
        }
    }
    res = lo;

done:
    return res;
}
