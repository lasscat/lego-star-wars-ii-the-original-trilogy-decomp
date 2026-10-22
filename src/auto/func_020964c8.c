#include "m2c.h"

extern void func_02007f24(s32 *a0, s32 a1, s32 a2);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 f1f;
} A;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} B;

s32 func_020964c8(volatile A *a, B *b) {
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 v;
    s32 lo;

    func_02007f24(&t1, 0, 0x3FE00000);
    v  = (s32) (((s64) a->f10 * t1 + 0x800) >> 12);
    lo = a->f4 - v;
    if (b->f0 < lo) {
        goto fail;
    }

    func_02007f24(&t2, 0, 0x3FE00000);
    v  = (s32) (((s64) a->f10 * t2 + 0x800) >> 12);
    lo = a->f4 + v;
    if (b->f0 > lo) {
        goto fail;
    }

    func_02007f24(&t3, 0, 0x3FE00000);
    v  = (s32) (((s64) a->f18 * t3 + 0x800) >> 12);
    lo = a->fc - v;
    if (b->f8 < lo) {
        goto fail;
    }

    func_02007f24(&t4, 0, 0x3FE00000);
    v  = (s32) (((s64) a->f18 * t4 + 0x800) >> 12);
    lo = a->fc + v;
    if (b->f8 > lo) {
        goto fail;
    }

    if (a->f1f) {
        return 1;
    }

    func_02007f24(&t5, 0, 0x3FE00000);
    v  = (s32) (((s64) a->f14 * t5 + 0x800) >> 12);
    lo = a->f8 - v;
    if (b->f4 < lo) {
        goto fail;
    }

    func_02007f24(&t6, 0, 0x3FE00000);
    v  = (s32) (((s64) a->f14 * t6 + 0x800) >> 12);
    lo = a->f8 + v;
    if (b->f4 <= lo) {
        return 1;
    }

fail:
    return 0;
}
