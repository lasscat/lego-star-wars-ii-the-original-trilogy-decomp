#include "m2c.h"

extern M2C_UNK data_0210dc2f;

s32 func_020bb388(s32 arg0, s32 arg1) {
    u32 bestVal = -1;
    s32 bestIdx = 0xff;
    s32 i;
    u32 b;
    u8 *p = (u8 *) &data_0210dc2f;

    for (i = 15; i >= 0; i--) {
        u32 a = p[4];
        b     = p[0x14];
        if (a == 0xff) {
            return i;
        }
        a &= 0xe0;
        if (a != 0x40) {
            if (a == 0x20) {
                if ((arg0 & 0xe0) != 0x20) {
                    b += 0x100;
                }
            }
            if (b < bestVal) {
                bestIdx = i;
                bestVal = b;
            }
        }
        p -= 1;
    }
    return ((u32) arg1 < bestVal) ? 0xff : bestIdx;
}
