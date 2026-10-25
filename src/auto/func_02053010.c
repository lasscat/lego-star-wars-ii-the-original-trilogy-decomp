#include "m2c.h"

typedef struct {
    u16 low : 2;
    u16 base : 4;
    u16 mid : 1;
    u16 wide : 1;
    u16 row : 5;
    u16 pad : 1;
    u16 size : 2;
} TileInfo;

extern u32 data_027e02a8;
extern void func_0205e624(void *, s32, s32);

void func_02053010(TileInfo info, u8 mode, s32 a, s32 b, s32 c) {
    s32 bank;
    s32 len;
    s32 t;
    u32 dst;

    if (data_027e02a8 & 0x200) {
        bank = 0;
    } else {
        bank = c;
    }
    if (mode) {
        len = 0x40;
    } else {
        len = (info.wide + 1) * 0x20;
    }
    dst = 0x6000000 + bank * 0x200000 + info.base * 0x4000 + len * a;
    if (info.wide) {
        t = b & 0xff;
        b = t + (t << 8);
    } else {
        t = b & 0xf;
        b = t + ((t << 12) + (t << 8) + (t << 4));
    }
    func_0205e624((void *) dst, b, len);
}
