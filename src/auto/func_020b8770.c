#include "m2c.h"

s32 func_020b8770(u8 *arg0, s32 arg1, u32 arg2) {
    s32 ret   = 0;
    s32 delta = 0;
    s32 lo    = arg1 & 0xF;
    s32 hi;

    if ((lo == 0) || ((hi = arg1 & 0xF0) == 0)) {
        ret = 0x10;
        if ((arg1 & 0xF0) == 0xF0) {
            delta = 0xF;
        } else if (lo == 0xF) {
            delta = -0xF;
        }
    } else if (lo == 0xF) {
        delta = arg1 >> 4;
    } else if (hi == 0xF0) {
        delta = -lo;
    }
    if (delta != 0) {
        u32 sum = *arg0 + delta;
        u32 b   = sum & 0xFF;
        *arg0   = sum;
        if (b > arg2) {
            if (delta < 0) {
                *arg0 = 0;
            } else {
                *arg0 = (u8) arg2;
            }
        }
    }
    return ret;
}
