#include "m2c.h"
s32 func_02066434(s32 a0, s32 a1, s32 a2) {
    s32 res = 0;
    s32 base;
    s32 idx;
    s32 count;
    if (a2 != 0) {
        base = *(u16 *) (a1 + 0xa);
        idx  = a2 - base;
        if (idx >= 0) {
            count = *(u16 *) (a1 + 0xc) - base;
            if (idx <= count) {
                res = *(u8 *) (*(volatile s32 *) (a1 + 0x14) + idx);
                return res;
            }
        }
        res = *(u8 *) (*(s32 *) (a1 + 0x14) + 1);
    }
    return res;
}
