#include "m2c.h"

void func_020c62a0(s32 a0, s32 a1, s32 a2) {
    u8 *base  = (u8 *) a0 + *(u32 *) (a0 + 8);
    u8 *tbl   = base + 4;
    u16 idx   = *(u16 *) (base + 0xa);
    u16 count = *(u16 *) (tbl + idx);
    u8 *entry = tbl + idx;
    u32 rel   = *(u32 *) (entry + count * a1 + 4);
    u32 *slot = (u32 *) (base + rel + 0xc);
    u32 v     = *slot;
    if (a2 != 0) {
        v |= 0x8000;
    } else {
        v &= ~0x8000;
    }
    *slot = v;
}
