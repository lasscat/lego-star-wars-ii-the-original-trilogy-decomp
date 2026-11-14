#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef union {
    u16 raw;
    struct {
        u16 r : 5;
        u16 g : 5;
        u16 b : 5;
        u16 a : 1;
    } c;
} Rgb;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u8 unk0[0xc];
    s32 near;
    s32 far;
    Vec3 color;
    s32 unk20;
    Fx scale;
    s32 unk28;
} Entry;

typedef struct {
    Entry *entries;
    u16 unk4;
    u16 cur;
    u8 unk8[0x14];
    Vec3 pos;
} Obj;

typedef struct {
    Vec3 dir;
    u16 rgb;
    u16 pad;
} Light;

extern Light data_027e0874[];

// NDS hardware divider and square-root unit registers (same names as func_02012744.cpp).
enum {
    DIV_CONTROL_ADDR     = 0x4000280,
    DIV_NUMERATOR_ADDR   = 0x4000290,
    DIV_DENOMINATOR_ADDR = 0x4000298,
    DIV_RESULT_ADDR      = 0x40002a0,
    SQRT_CONTROL_ADDR    = 0x40002b0,
    SQRT_RESULT_ADDR     = 0x40002b4,
    SQRT_PARAMETER_ADDR  = 0x40002b8,
};

enum {
    FX_ONE    = 0x1000,  // 1.0 in Q12
    COLOR_MAX = 0x1f000, // 31.0 in Q12, the largest 5-bit channel value
};

static inline Entry *cur_entry(Obj *obj) {
    return &obj->entries[obj->cur];
}

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_make(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void vec_scale(Vec3 *d, const Vec3 *s, s32 t) {
    Vec3 tmp;
    vec_make(&tmp, fx_mul(s->x, t), fx_mul(s->y, t), fx_mul(s->z, t));
    vec_set(d, &tmp);
}

static inline void vec_mul_fx(Vec3 *v, const Fx *s) {
    Fx sx, sy, sz;
    sx   = *s;
    v->x = fx_mul(v->x, sx.v);
    sy   = *s;
    v->y = fx_mul(v->y, sy.v);
    sz   = *s;
    v->z = fx_mul(v->z, sz.v);
}

static inline Fx *fx_init(Fx *f, s32 v) {
    f->v = v;
    return f;
}

static inline Fx *fx_set(Fx *f, const Fx *s) {
    f->v = s->v;
    return f;
}

static inline Fx *fx_copy(Fx *d, const Fx *s) {
    *d = *s;
    return d;
}

static inline Fx *fx_max(Fx *r, const Fx *a, const Fx *b) {
    if (b->v < a->v) {
        return fx_set(r, a);
    }
    return fx_set(r, b);
}

static inline Fx *fx_min(Fx *r, const Fx *a, const Fx *b) {
    if (a->v < b->v) {
        return fx_set(r, a);
    }
    return fx_set(r, b);
}

// min(max(*x, lo), hi). The nested copy chain keeps one stack temporary per value, which
// is what the matched register allocation needs.
static inline s32 clamp(const Fx *x, s32 lo, s32 hi) {
    Fx t2, t1, flo, fhi, a, m, b, v;
    return fx_min(&t2, fx_copy(&m, fx_max(&t1, fx_copy(&a, fx_init(&flo, lo)), fx_copy(&v, x))),
                  fx_copy(&b, fx_init(&fhi, hi)))
        ->v;
}

// Fill entry idx of the data_027e0874 table from the point pos as seen from obj.
// d = pos - obj->pos. dist = round(|d|) comes from the square-root unit. If dist >= the
// current entry's far value, nothing is written. The divider computes 2^24 / dist, so d * inv
// is d / |d| in Q12. Each component is clamped to [-1.0, 1.0).
// The colour starts as the entry's colour. When dist > near, it is multiplied by (far - dist)
// and then by the entry's scale field. Each channel is capped at 31.0, then packed as 5:5:5
// with bit 15 clear. Both the packed colour and the direction are stored into entry idx.
void func_0206205c(Obj *obj, s32 idx, const Vec3 *pos) {
    s32 x, y, z;
    Vec3 d;
    Vec3 color;
    Rgb rgb;
    s64 sq;
    s32 dist;
    Fx inv;
    Entry *e;

    z   = pos->z - obj->pos.z;
    y   = pos->y - obj->pos.y;
    x   = pos->x - obj->pos.x;
    d.x = x;
    d.y = y;
    d.z = z;
    sq  = (s64) x * x;
    sq += (s64) y * y;
    sq += (s64) z * z;
    *(volatile u16 *) SQRT_CONTROL_ADDR   = 1;
    *(volatile u64 *) SQRT_PARAMETER_ADDR = sq << 2;
    while (*(volatile u16 *) SQRT_CONTROL_ADDR & 0x8000) {
    }
    dist = (*(volatile s32 *) SQRT_RESULT_ADDR + 1) >> 1;
    if (cur_entry(obj)->far <= dist) {
        return;
    }
    *(volatile u16 *) DIV_CONTROL_ADDR     = 0;
    *(volatile u32 *) DIV_NUMERATOR_ADDR   = 0x1000000;
    *(volatile u64 *) DIV_DENOMINATOR_ADDR = (u32) dist;
    e                                      = cur_entry(obj);
    color.x                                = e->color.x;
    color.y                                = e->color.y;
    color.z                                = e->color.z;
    e                                      = cur_entry(obj);
    if (dist > e->near) {
        s32 t = dist - e->near;
        t     = (cur_entry(obj)->far - cur_entry(obj)->near) - t;
        vec_scale(&color, &e->color, t);
        vec_mul_fx(&color, &cur_entry(obj)->scale);
    }
    while (*(volatile u16 *) DIV_CONTROL_ADDR & 0x8000) {
    }
    inv.v = *(volatile s32 *) DIV_RESULT_ADDR;
    vec_mul_fx(&d, &inv);
    d.x = clamp((const Fx *) &d.x, -FX_ONE, FX_ONE - 1);
    d.y = clamp((const Fx *) &d.y, -FX_ONE, FX_ONE - 1);
    d.z = clamp((const Fx *) &d.z, -FX_ONE, FX_ONE - 1);
    if (color.x > COLOR_MAX) {
        color.x = COLOR_MAX;
    }
    if (color.y > COLOR_MAX) {
        color.y = COLOR_MAX;
    }
    if (color.z > COLOR_MAX) {
        color.z = COLOR_MAX;
    }
    rgb.c.r                = (u8) (color.x >> 12);
    rgb.c.g                = (u8) (color.y >> 12);
    rgb.c.b                = (u8) (color.z >> 12);
    rgb.c.a                = 0;
    data_027e0874[idx].rgb = rgb.raw;
    vec_set(&data_027e0874[idx].dir, &d);
}
