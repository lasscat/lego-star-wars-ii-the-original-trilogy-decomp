#include "m2c.h"

typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u16 v;
} Angle;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} V3;

typedef struct {
    u8 pad0[0xb0];
    V3 pos;
    u8 pad1[0xc8 - 0xbc];
    u16 pitch;
    u16 yaw;
    u8 pad2[4];
    u8 dirty;
    u8 pos_dirty;
} Obj;

typedef struct {
    u8 pad[0x98];
    Obj *objs[1];
} Owner;

enum {
    REG_SQRTCNT     = 0x040002b0,
    REG_SQRT_RESULT = 0x040002b4,
    REG_SQRT_PARAM  = 0x040002b8,
    SQRT_MODE_64    = 1,
    MATH_BUSY       = 0x8000,
};

extern s32 func_02062b3c(u32);
extern void func_02074970(s32, void *, M2C_UNK, M2C_UNK);
extern void func_020749b0(s32, void *, M2C_UNK, M2C_UNK);
extern s16 func_020985d8(s32, s32);

static inline void vec_copy(V3 *d, const V3 *s) {
    if (d != s) {
        d->x.v = s->x.v;
        d->y.v = s->y.v;
        d->z.v = s->z.v;
    }
}

/* Subtracting through Fx pointers loads b before a; a plain a->x.v - b->x.v loads a first
 * and gives a different register assignment. */
static inline s32 fx_sub(const Fx *a, const Fx *b) {
    return a->v - b->v;
}

/* o = a - b; computing z before y is needed for the target register assignment. */
static inline void vec_sub(V3 *o, const V3 *a, const V3 *b) {
    s32 x, y, z;
    z      = fx_sub(&a->z, &b->z);
    y      = fx_sub(&a->y, &b->y);
    x      = fx_sub(&a->x, &b->x);
    o->x.v = x;
    o->y.v = y;
    o->z.v = z;
}

static inline int vec_ne(const V3 *a, const V3 *b) {
    if (a->x.v != b->x.v || a->y.v != b->y.v || a->z.v != b->z.v) {
        return 1;
    }
    return 0;
}

static inline void ang_atan2(Angle *out, Fx x, Fx z) {
    out->v = func_020985d8(x.v, z.v);
}

static inline void ang_pitch(Angle *out, Fx y, s32 dist) {
    u16 u  = func_020985d8(y.v, dist);
    out->v = -u;
}

static inline void set_yaw(Obj *a, Angle yaw) {
    if (a->yaw != yaw.v) {
        a->yaw   = yaw.v;
        a->dirty = 1;
    }
}

static inline void set_pitch(Obj *a, Angle pitch) {
    if (a->pitch != pitch.v) {
        a->pitch = pitch.v;
        a->dirty = 1;
    }
}

/* Called from func_02073b68 (with index 0) and func_02074490.
 * Builds two points p and q, swapping in the alternative pair when func_02062b3c(0x32) is nonzero,
 * and adjusts the y (func_02074970) and z (func_020749b0) components of each.
 * Object arg0->objs[arg1] (+0x98) is moved to p (dirty byte +0xd1 when the position changed).
 * With d = q - p it then sets the yaw (+0xca) to func_020985d8(d.x, d.z) and the pitch (+0xc8) to
 * -func_020985d8(d.y, sqrt(d.x^2 + d.z^2)) (hardware square-root unit); dirty byte +0xd0. */
void func_02074704(Owner *arg0, s32 arg1) {
    V3 lo;
    V3 hi;
    V3 p;
    V3 q;
    V3 d;
    s64 t;
    Fx dist;
    Obj *o;
    Fx qz;
    Fx qx;
    Angle yaw;
    Angle pitch;

    lo.x.v = -0x21000;
    lo.y.v = -0x4000;
    lo.z.v = 0x1e000;
    hi.x.v = 0x21000;
    hi.y.v = -0x4000;
    hi.z.v = 0x1e000;
    p.x.v  = 0x21000;
    p.y.v  = -0x4000;
    p.z.v  = 0x1e000;
    q.x.v  = -0x21000;
    q.y.v  = -0x4000;
    q.z.v  = 0x1e000;
    if (func_02062b3c(0x32) != 0) {
        vec_copy(&p, &lo);
        vec_copy(&q, &hi);
    }
    func_02074970((s32) arg0, &p, 0, 0x14);
    func_020749b0((s32) arg0, &p, 0, 0x14);
    func_02074970((s32) arg0, &q, 0, 0x14);
    func_020749b0((s32) arg0, &q, 0, 0x14);
    vec_sub(&d, &q, &p);
    o = arg0->objs[arg1];
    if (vec_ne(&o->pos, &p)) {
        vec_copy(&o->pos, &p);
        o->pos_dirty = 1;
    }
    qz = d.z;
    qx = d.x;
    ang_atan2(&yaw, qx, qz);
    set_yaw(arg0->objs[arg1], yaw);
    t = (s64) d.x.v * d.x.v;
    t += (s64) d.z.v * d.z.v;
    *(vu16 *) REG_SQRTCNT   = SQRT_MODE_64;
    *(u64 *) REG_SQRT_PARAM = t << 2;
    while (*(vu16 *) REG_SQRTCNT & MATH_BUSY) {
    }
    dist.v = ((s32) * (vu32 *) REG_SQRT_RESULT + 1) >> 1;
    ang_pitch(&pitch, d.y, dist.v);
    set_pitch(arg0->objs[arg1], pitch);
}
