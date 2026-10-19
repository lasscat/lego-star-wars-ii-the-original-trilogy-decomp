#include "m2c.h"
s32 func_020ca988(void) {
    u32 v;
    v = (((s32) ((*(volatile u16 *) 0x0400000A) & 0x1F00)) >> 8) << 11;
    return ((((*(volatile u32 *) 0x04000000) & 0x38000000) >> 27) << 16) + 0x06000000 + v;
}
