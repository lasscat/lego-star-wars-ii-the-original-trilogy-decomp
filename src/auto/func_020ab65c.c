#include "m2c.h"

/* Reads a packed 32-bit value and returns the product of its two 11-bit fields. */
s32 func_020ab65c(M2C_UNK a0, s32 a1) {
    s32 *t   = M2C_FIELD(a0, s32 *, 0xc);
    u16 idx  = M2C_FIELD(t, u16 *, 0x42);
    u8 *base = (u8 *) t + 0x3c;
    u16 v    = M2C_FIELD(base + idx, u16 *, 0);
    u32 val  = M2C_FIELD((s32) (base + idx) + v * a1 + 8, u32 *, 0);
    return (u16) (val & 0x7ff) * (((val & (0x7ff << 11)) << 5) >> 16);
}
