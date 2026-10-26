#include "m2c.h"

typedef struct {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 a : 1;
} Color555;

typedef struct {
    u8 *count;
} CountRef;

typedef struct {
    u8 pad0[0x5C];
    u8 *countPtr;
    Color555 colors[1];
    u8 pad[0x958 - 0x62];
    s32 cur;
    s32 target;
    s32 step;
} Fader;

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

void func_02093a00(Fader *f) {
    s32 up, step, cur;
    u32 i;

    step = f->step;
    if (step == 0) {
        return;
    }
    cur = f->cur;
    up  = 1;
    if (cur > f->target) {
        up = 0;
    }
    f->cur = cur + step;
    if ((up && f->cur >= f->target) || (!up && f->cur <= f->target)) {
        f->cur  = f->target;
        f->step = 0;
    }
    for (i = 0; i < *f->countPtr; i++) {
        f->colors[i].b = FxMul(f->colors[i].b << 12, f->cur) >> 12;
        f->colors[i].g = FxMul(f->colors[i].g << 12, f->cur) >> 12;
        f->colors[i].r = FxMul(f->colors[i].r << 12, f->cur) >> 12;
    }
}
