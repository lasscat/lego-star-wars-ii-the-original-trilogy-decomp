#include "m2c.h"

typedef struct {
    s32 v;
} Fx;

s32 FX_Sqrt(s32 x);

void func_0200a34c(s32 *out, Fx b, Fx c) {
    s32 nb;
    s32 d;
    s32 root;
    s32 t0;
    s32 t1;

    d    = (s32) (((s64) b.v * b.v + 0x800) >> 12) - (s32) (((s64) c.v * 0x4000 + 0x800) >> 12);
    root = FX_Sqrt(d);
    nb   = -b.v;
    t0   = (nb + root) >> 1;
    t1   = (nb - root) >> 1;
    *out = 0;
    if (t0 > 0) {
        *out = t0;
        if (t1 > 0 && t1 < t0) {
            *out = t1;
        }
    } else {
        *out = t1;
    }
}
