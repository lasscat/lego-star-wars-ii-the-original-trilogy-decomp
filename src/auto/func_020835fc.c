#include "m2c.h"

extern void func_02007f24(s32 *, f64);
typedef struct WordArg {
    s32 v;
} WordArg;

extern s32 func_0200aef8(void *, void *, WordArg);
extern s32 func_0201eec4(s32 *, s32 *, WordArg);

typedef struct Bounds {
    s32 pad0;
    s32 cx, cy, cz;
    s32 ex, ey, ez;
    u8 kind;
} Bounds;

static inline s32 half(void) {
    s32 h;
    func_02007f24(&h, 0.5);
    return h;
}

enum {
    FX_SHIFT = 12,
    FX_ROUND = 0x800
};

/* 20.12 fixed-point multiply, rounded to nearest. */
static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_ROUND) >> FX_SHIFT);
}

static inline WordArg half_arg(const s32 *ext) {
    s32 h;
    WordArg w;
    func_02007f24(&h, 0.5);
    w.v = fx_mul(*ext, h);
    return w;
}

/*
 * Returns 1 when point p passes the test selected by b->kind, else 0.
 * kind 0: p[0..2] lies within c -/+ e * 0.5 on all three axes.
 * kind 1: func_0200aef8(p, &b->cx, ex * 0.5) decides.
 * kind 2: p[1] lies within cy -/+ ey * 0.5, then func_0201eec4(p, &b->cx, ex) decides.
 */
s32 func_020835fc(Bounds *b, s32 *p) {
    int bound;

    switch (b->kind) {
        case 0:
            bound = fx_mul(b->ex, half());
            bound = b->cx - bound;
            if (p[0] < bound) {
                break;
            }
            bound = fx_mul(b->ex, half());
            bound = b->cx + bound;
            if (p[0] > bound) {
                break;
            }
            bound = fx_mul(b->ey, half());
            bound = b->cy - bound;
            if (p[1] < bound) {
                break;
            }
            bound = fx_mul(b->ey, half());
            bound = b->cy + bound;
            if (p[1] > bound) {
                break;
            }
            bound = fx_mul(b->ez, half());
            bound = b->cz - bound;
            if (p[2] < bound) {
                break;
            }
            bound = fx_mul(b->ez, half());
            bound = b->cz + bound;
            if (p[2] > bound) {
                break;
            }
            return 1;
        case 1:
            if (func_0200aef8(p, &b->cx, half_arg(&b->ex)) != 0) {
                return 1;
            }
            break;
        case 2:
            bound = fx_mul(b->ey, half());
            bound = b->cy - bound;
            if (p[1] < bound) {
                break;
            }
            bound = fx_mul(b->ey, half());
            bound = b->cy + bound;
            if (p[1] > bound) {
                break;
            }
            if (func_0201eec4(p, &b->cx, *(WordArg *) &b->ex) != 0) {
                return 1;
            }
            break;
    }
    return 0;
}
