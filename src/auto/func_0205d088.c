#include "m2c.h"

s32 func_0205d088(s32 arg0, u32 arg1) {
    u8 i;
    u32 mask = (u16) arg1;
    for (i = 0; i < 4; i++) {
        u32 idx = i;
        u32 v;
        if (i == 4) {
            idx = *(u8 *) (arg0 + 0x2a);
        }
        v = *(u16 *) (arg0 + idx * 10);
        if (v & mask) {
            return 1;
        }
    }
    return 0;
}
