/* Reconstructed from USA ARM9 at 0x020c044c */
#include "m2c.h"

enum {
    FX_SHIFT = 12,
    FX_ONE   = 0x1000,
    FX_HALF  = 0x800
};

extern s32 data_0210e2f8[];
extern s32 data_0210e3f8[];
s32 FX_Div(s32, s32);

void func_020c044c(void *arg0, void *arg1) {
    s32 span;
    s32 inv;
    s32 *f = (s32 *) arg0;
    s32 *g = (s32 *) arg1;

    /* span = whole-number difference f[3] - f[2], scaled by g[29] unless f[4] is set */
    if (f[4] != 0) {
        span = (f[3] - f[2]) >> FX_SHIFT;
    } else {
        s32 factor = g[29];
        s64 prod_a = (s64) f[2] * factor + FX_HALF;
        s32 prod_b;
        prod_a = (s32) (prod_a >> FX_SHIFT);
        prod_b = (s32) (((s64) f[3] * factor + FX_HALF) >> FX_SHIFT);
        span   = (prod_b >> FX_SHIFT) - ((s32) prod_a >> FX_SHIFT);
    }
    /* fixed-point reciprocal of the span */
    inv = FX_Div(FX_ONE, span << FX_SHIFT);
    if (f[5] >= 0) {
        s32 d = f[5];
        d -= g[12];
        d                    = (s32) (((s64) d * inv + FX_HALF) >> FX_SHIFT);
        data_0210e2f8[g[19]] = d;
    } else {
        data_0210e2f8[g[19]] = 0;
    }
    if (f[6] >= 0) {
        s32 d = f[6];
        d -= g[13];
        d                    = (s32) (((s64) d * inv + FX_HALF) >> FX_SHIFT);
        data_0210e3f8[g[19]] = d;
    } else {
        data_0210e3f8[g[19]] = 0;
    }
}
