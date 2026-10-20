#include "m2c.h"

void func_02090888(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u64 v;
    u32 w;
    u8 *p;
    u32 *tbl;
    u32 *e;
    v               = (u64) (u32) a2 * 0x1ff6210ULL;
    w               = (u32) (v >> 6);
    p               = (u8 *) a0 + 0x28;
    tbl             = (u32 *) (p + 0x400);
    e               = tbl + a1 * 4;
    e[1]            = a2;
    e[2]            = w;
    e[0]            = 0;
    ((u8 *) e)[0xF] = a3;
    ((u8 *) e)[0xE] = a4;
    ((u8 *) e)[0xC] = 1;
    ((u8 *) e)[0xD] = 0;
}
