#include "m2c.h"

extern u8 data_020f0204[];
extern u8 data_020f01fc[];

s32 func_020832d0(s32 a0, s32 a1, s32 a2) {
    s32 *p;
    s32 count;
    s32 i;

    if (a2 == 0xfa || a2 < (s32) data_020f0204[a1] || a2 > (s32) data_020f01fc[a1]) {
        return -1;
    }
    p     = (s32 *) a0 + a1;
    count = p[0x52];
    i     = 0;
    while (i < count && ((u8 **) p)[0x4d][i] != a2) {
        i++;
    }
    if (i >= count) {
        return -1;
    }
    return i;
}
