#include "m2c.h"

extern M2C_UNK data_02104344;

void func_02062b6c(s32 arg0);

u32 func_02062bb4(void) {
    u32 *p;
    u32 *q;
    u32 *e;
    u32 *s;
    u32 a;
    u32 b;
    u32 x;
    s32 n;

    p = M2C_FIELD(&data_02104344, u32 **, 0x10);
    q = M2C_FIELD(&data_02104344, u32 **, 0x10) + 2;
    e = M2C_FIELD(&data_02104344, u32 **, 0x10) + 397;
    if (M2C_FIELD(&data_02104344, s32 *, 8) < -1) {
        func_02062b6c(M2C_FIELD(&data_02104344, s32 *, 0x1C));
    }
    M2C_FIELD(&data_02104344, s32 *, 8)    = 0x26F;
    s                                      = M2C_FIELD(&data_02104344, u32 **, 0x10);
    M2C_FIELD(&data_02104344, u32 **, 0xC) = s + 1;
    a                                      = s[0];
    b                                      = s[1];
    n                                      = 0xE4;
    while (--n) {
        x    = *e++ ^ (((a & 0x80000000u) | (b & 0x7fffffffu)) >> 1) ^ ((b & 1u) ? 0x9908B0DFu : 0u);
        *p++ = x;
        a    = b;
        b    = *q++;
    }
    e = M2C_FIELD(&data_02104344, u32 **, 0x10);
    n = 0x18D;
    while (--n) {
        x    = *e++ ^ (((a & 0x80000000u) | (b & 0x7fffffffu)) >> 1) ^ ((b & 1u) ? 0x9908B0DFu : 0u);
        *p++ = x;
        a    = b;
        b    = *q++;
    }
    x  = M2C_FIELD(&data_02104344, u32 **, 0x10)[0];
    *p = *e ^ (((a & 0x80000000u) | (x & 0x7fffffffu)) >> 1) ^ ((x & 1u) ? 0x9908B0DFu : 0u);
    x ^= x >> 11;
    x ^= (0x9D2C5680u & (x << 7));
    x ^= (0xEFC60000u & (x << 15));
    x ^= x >> 18;
    return x;
}
