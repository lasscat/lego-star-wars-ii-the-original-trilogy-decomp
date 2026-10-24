#include "m2c.h"

u32 func_0208c840(void *);

void func_02087124(u8 *base) {
    u32 total;
    s32 i;
    u32 a;
    s32 j;
    u32 b;

    total = 0;
    total += func_0208c840(base + 0x34);
    a = 0;
    for (i = 0; i < 0x20; i++) {
        a += (*(u32 *) (base + 0x4520) >> i) & 1;
    }
    total += a;
    b = 0;
    for (j = 0; j < 0x20; j++) {
        b += (*(u32 *) (base + 0x4514) >> j) & 1;
    }
    total += b;
    if (total != 0) {
        base[0x455F] = (total * 100) / 0xDD;
    } else {
        base[0x455F] = 0;
    }
}
