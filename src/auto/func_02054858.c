#include "m2c.h"

extern s32 func_0205e6e0(s32, void *, s32);

void func_02054858(s32 *out, u16 *p, u32 a, ...) {
    u16 **ap = (u16 **) &p; // FAKE: same-type cast keeps p memory-resident (plain &p is promoted to a register)
    u16 *q   = p;
    u32 v;
    u32 x;
    u32 y;
    (*ap)++;
    v = *q << 16;
    v |= *(*ap)++;
    x      = (*ap)[0];
    y      = (*ap)[1];
    out[0] = x << 12;
    out[1] = y << 12;
    p += 2;
    func_0205e6e0((a << 21) + 0x6000000, p, v);
}
