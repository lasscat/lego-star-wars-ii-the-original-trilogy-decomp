#include "m2c.h"

void func_020c61e0(s32 a0, s32 a1, s32 a2) {
    u32 cnt;
    s32 off;
    s32 base;
    s32 i;
    u32 idx;
    u32 ent;
    u32 p;
    u32 v;
    u16 *q;
    cnt  = *(u8 *) (a0 + 0x18);
    off  = *(s32 *) (a0 + 0x8);
    base = a0 + off;
    for (i = 0; i < cnt; i++) {
        idx = *(u16 *) (base + 0xA);
        ent = *(u16 *) ((u8 *) base + 4 + idx);
        p   = (u32) ((u8 *) base + 4 + idx) + ent * i;
        v   = *(s32 *) (p + 4);
        q   = (u16 *) (base + v + 0x1E);
        if (a1 != 0) {
            *q |= a2;
        } else {
            *q &= ~a2;
        }
    }
}
