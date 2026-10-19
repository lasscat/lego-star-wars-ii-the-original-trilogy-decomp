#include "m2c.h"

u32 func_0205d060(s32 arg0, s32 arg1, s32 arg2) {
    u32 flags;

    if (arg2 == 4) {
        arg2 = *(u8 *) (arg0 + 0x2A);
    }
    flags = *(u16 *) (arg0 + arg2 * 10);
    return (flags & (u16) arg1) != 0;
}
