#include "m2c.h"

/* func_020bd75c - turns a spherical spec into a fixed point (12 bit fraction)
 * vector.
 *
 * The spec holds a length source (two words handed to func_02062ab4), and a
 * yaw and a pitch angle, each with a spread.  A random jitter in
 * [-spread/2, spread/2) is added to each angle, the angle's top 12 bits index
 * the sine/cosine table and the length is scaled by the resulting factors.
 * The jitter is built as a one-halfword angle struct (a compound literal) and
 * handed to the adder by value, which is what keeps it in the stack frame.
 */

extern const s16 data_020f88c4[];
u32 func_02062b10(s32);
s32 func_02062ab4(s32, s32);

typedef struct {
    s32 a;
    s32 b;
    u16 yaw;
    u16 yawSpread;
    u16 pitch;
    u16 pitchSpread;
} Spec;

typedef struct {
    u16 v;
} Ang;

static inline u16 addA(u16 base, Ang d) {
    return base + d.v;
}

void func_020bd75c(s32 *out, Spec *spec) {
    s32 len;
    u16 y, p;
    s32 s1, c1, s2, c2, t;

    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    len    = func_02062ab4(spec->a, spec->b);
    y      = addA(spec->yaw, (Ang) {func_02062b10(spec->yawSpread) - (spec->yawSpread >> 1)});
    p      = addA(spec->pitch, (Ang) {func_02062b10(spec->pitchSpread) - (spec->pitchSpread >> 1)});
    s1     = data_020f88c4[(y >> 4) * 2];
    c1     = data_020f88c4[(y >> 4) * 2 + 1];
    s2     = data_020f88c4[(p >> 4) * 2];
    c2     = data_020f88c4[(p >> 4) * 2 + 1];
    t      = (s32) (((s64) len * s1 + 0x800) >> 12);
    out[0] = (s32) (((s64) t * c2 + 0x800) >> 12);
    out[1] = (s32) (((s64) len * c1 + 0x800) >> 12);
    out[2] = (s32) (((s64) t * s2 + 0x800) >> 12);
}
