#include "m2c.h"

void func_0200c868(s32 a0, s32 a1) {
    s32 off = a1 * 0x38;

    M2C_FIELD(a0, s8 *, off + 0x3CD)   = 1;
    M2C_FIELD(a0, s8 *, off + 0x3CC)   = 1;
    M2C_FIELD((a0 + 0x3D0), s8 *, off) = M2C_FIELD((a0 + 0x3D0), s8 *, off) + 1;
}
