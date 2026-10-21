#include "m2c.h"

s32 func_020ab6dc(s32 arg0, s32 arg1) {
    s32 p    = *(s32 *) (arg0 + 0xC);
    u32 idx  = *(u16 *) (p + 0x34);
    s32 base = p + idx;
    u32 j    = *(u16 *) (base + 6);
    u32 v    = *(u16 *) (base + j);

    return *(u16 *) (base + j + v * arg1 + 4) << 3;
}
