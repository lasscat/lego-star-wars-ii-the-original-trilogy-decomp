#include "m2c.h"

typedef struct {
    u16 v;
} Half;

typedef struct {
    Half x;
    Half y;
    Half z;
    u16 pad;
} Rot3;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u8 pad0[0x40];
    Rot3 rot;
    u8 rot_changed;
    u8 pad49[0x358 - 0x49];
    Rot3 target;
} Obj;

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline Half half_sub(Half *a, Half b, Half *r) {
    r->v = a->v - b.v;
    return *r;
}

static inline Half half_add(const Half *a, Half b, Half *r) {
    r->v = a->v + b.v;
    return *r;
}

static inline Half half_scale(s16 a, Fx t, Half *r) {
    r->v = fx_mul(a << 12, t.v) >> 12;
    return *r;
}

static inline Half half_get(const Half *a) {
    return *a;
}

static inline void half_scale_by(Half *a, Fx t, Half *r) {
    a->v = half_scale(a->v, t, r).v;
}

static inline Half half_pass(const Half b) {
    return b;
}
static inline s32 rot_eq(const Rot3 *a, const Rot3 *b) {
    Half bx = half_get(&b->x);
    return a->x.v == bx.v && a->y.v == half_pass(b->y).v && a->z.v == half_pass(b->z).v;
}
static inline void rot_sync(Obj *o, const Rot3 *n) {
    if (rot_eq(n, &o->rot)) {
        return;
    }
    o->rot.x.v     = half_get(&n->x).v;
    o->rot.y.v     = half_get(&n->y).v;
    o->rot.z.v     = half_get(&n->z).v;
    o->rot_changed = 1;
}

static inline void rot_sub3(Rot3 *d, Rot3 *a, Half x, Half y, Half z) {
    half_sub(&a->x, x, &d->x);
    half_sub(&a->y, y, &d->y);
    half_sub(&a->z, z, &d->z);
}

/* Sets rot to target + (rot - target) * t (Q12 factor from the callers FX_Div ratio);
 * when the result differs from rot, stores it and sets rot_changed. */
void func_020a389c(Obj *obj, Fx t) {
    Rot3 d;
    Rot3 n;
    Half sx;
    Half sy;
    Half sz;
    rot_sub3(&d, &obj->rot, obj->target.x, obj->target.y, obj->target.z);
    half_scale_by(&d.x, t, &sx);
    half_scale_by(&d.y, t, &sy);
    half_scale_by(&d.z, t, &sz);
    half_add(&obj->target.x, d.x, &n.x);
    half_add(&obj->target.y, d.y, &n.y);
    half_add(&obj->target.z, d.z, &n.z);
    rot_sync(obj, &n);
}
