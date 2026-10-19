#include "m2c.h"

u32 func_020ab6a0(void *arg0, s32 arg1) {
    s32 p    = *(s32 *) ((s8 *) arg0 + 0xC);
    u32 idx  = *(u16 *) ((s8 *) p + 0x42);
    s32 base = p + 0x3c;
    u32 v    = *(u16 *) ((u8 *) base + idx);
    u32 w    = *(u32 *) ((u8 *) base + idx + v * arg1 + 4);
    return (u32) (w << 16) >> 13;
}
