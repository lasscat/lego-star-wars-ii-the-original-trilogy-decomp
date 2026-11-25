#include "m2c.h"

enum {
    REG_DIVCNT      = 0x04000280,
    REG_DIV_NUMER   = 0x04000290,
    REG_DIV_DENOM   = 0x04000298,
    REG_DIV_RESULT  = 0x040002a0,
    REG_SQRTCNT     = 0x040002b0,
    REG_SQRT_RESULT = 0x040002b4,
    REG_SQRT_PARAM  = 0x040002b8,
    DIV_MODE_64_64  = 2,
    SQRT_MODE_64    = 1,
    MATH_BUSY       = 0x8000,
    FX_SHIFT        = 12,
    FX_ONE          = 0x1000,
    FX_HALF         = 0x800,
    MIN_DIR_LEN_SQ  = 16, /* Q12 */
};

typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u8 pad[0x2d8];
    s32 f2d8; /* 0x2d8: Q12 divisor of the segment length */
    s32 f2dc; /* 0x2dc: Q12 factor of the segment length */
} Spline;

void func_020111c4(Fx *out, const Vec3 *v);               /* squared length */
s32 func_020a8214(void *self, Vec3 *a, Vec3 *b, Vec3 *c); /* orientation of a, b, c in the X/Z plane */
s32 FX_Div(s32 a, s32 b);

extern Vec3 data_020ff9b4;         /* zero vector */
extern const s16 data_020f98c4[2]; /* { sin, cos } of a quarter turn: 1.0, 0 */
extern const s16 data_020fb8c4[2]; /* { sin, cos } of three quarters: -1.0, 0 */

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_HALF) >> FX_SHIFT);
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_sub(const Vec3 *a, const Vec3 *b, Vec3 *d) {
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline void vec_add(const Vec3 *a, const Vec3 *b, Vec3 *d) {
    s32 z = a->z;
    s32 y;
    s32 x;
    z += b->z;
    y = a->y;
    y += b->y;
    x = a->x;
    x += b->x;
    d->x = x;
    d->y = y;
    d->z = z;
}

/* length, with the 64-bit hardware square root */
static inline s32 vec_mag(const Vec3 *v) {
    s64 t = (s64) v->x * v->x;
    t += (s64) v->y * v->y;
    t += (s64) v->z * v->z;
    (*(vu16 *) REG_SQRTCNT)   = SQRT_MODE_64;
    (*(u64 *) REG_SQRT_PARAM) = t << 2;
    while ((*(vu16 *) REG_SQRTCNT) & MATH_BUSY) {
    }
    return (s32) ((*(vu32 *) REG_SQRT_RESULT) + 1) >> 1;
}

/* d = s / |s|: (1 / |s|^2) from the hardware divider times |s| from the hardware square root */
static inline void vec_normalize(Vec3 *d, const Vec3 *s) {
    s64 t;
    s32 sqrt;
    s64 div;

    t = (s64) s->x * s->x;
    t += (s64) s->y * s->y;
    t += (s64) s->z * s->z;

    (*(vu16 *) REG_DIVCNT)    = DIV_MODE_64_64;
    (*(vu64 *) REG_DIV_NUMER) = 1LL << 56;
    (*(vu64 *) REG_DIV_DENOM) = t;

    (*(vu16 *) REG_SQRTCNT)   = SQRT_MODE_64;
    (*(u64 *) REG_SQRT_PARAM) = t << 2;

    while ((*(vu16 *) REG_SQRTCNT) & MATH_BUSY) {
    }
    sqrt = (s32) (*(vu32 *) REG_SQRT_RESULT);

    while ((*(vu16 *) REG_DIVCNT) & MATH_BUSY) {
    }
    div = (s64) (*(u64 *) REG_DIV_RESULT);

    div *= sqrt;

    d->x = (s32) ((div * s->x + (1LL << 44)) >> 45);
    d->y = (s32) ((div * s->y + (1LL << 44)) >> 45);
    d->z = (s32) ((div * s->z + (1LL << 44)) >> 45);
}

static inline void vec_unit(Vec3 *v) {
    if (v->x == 0 && v->y == 0 && v->z == 0) {
        vec_set(v, &data_020ff9b4);
    } else {
        vec_normalize(v, v);
    }
}

/* rotate about Y by the angle whose { sin, cos } pair is sc */
static inline void vec_rot_y(Vec3 *v, const s16 *sc) {
    s32 s = sc[0];
    s32 c = sc[1];
    s32 x = v->x;
    s32 z = v->z;
    s32 t;
    s64 m;

    m    = z;
    m    = (m * s + FX_HALF) >> FX_SHIFT;
    t    = (s32) m;
    v->x = fx_mul(x, c);
    v->x += t;
    m    = x;
    m    = (m * s + FX_HALF) >> FX_SHIFT;
    v->z = fx_mul(z, c) - (s32) m;
}

static inline void vec_scale(Vec3 *v, const Fx *s) {
    Fx x;
    Fx y;
    Fx z;
    x    = *s;
    v->x = fx_mul(v->x, x.v);
    y    = *s;
    v->y = fx_mul(v->y, y.v);
    z    = *s;
    v->z = fx_mul(v->z, z.v);
}

/* value of r, 0 for a null r */
static inline s32 fx_val(const Fx *r) {
    const Fx *p = r;
    s32 v       = 0;

    if (p) { // FAKE: always-true null test keeps the add rX,sp / ldr form
        v = p->v;
    }
    return v;
}

/* one component of the cubic Bezier p3*t^3 + 3*p2*t^2*u + 3*p1*t*u^2 + p0*u^3, u = 1 - t */
static inline s32 bez(const s32 *p0, const s32 *p2, const s32 *p3, const s32 *p1, int u, int t) {
    s32 r;
    s64 v;
    s64 w = (s64) *p0 * u;
    w     = (w + FX_HALF) >> FX_SHIFT;
    v     = (s64) *p3 * t;
    v     = (v + FX_HALF) >> FX_SHIFT;
    r     = fx_mul(fx_mul((s32) v, t), t) + fx_mul(fx_mul(fx_mul(*p2 * 3, t), t), u);
    return (r + fx_mul(fx_mul(fx_mul(*p1 * 3, t), u), u)) + fx_mul(fx_mul((s32) w, u), u);
}

/*
 * Point at parameter t (Q12) on the curved path segment from a (t = 0) to b (t = 1).
 * pb is the path point next to a and pa the one next to b (func_020a6cac fetches them from the point list).
 *
 * At each end the two unit directions that meet there are added, and the sum is turned a quarter turn about Y,
 * with the side given by the orientation test, and normalised.  This is the tangent of the curve at that end; scaled by
 * (segment length / f2d8) * f2dc it gives the inner control points c1 (from b) and c2 (from a) of a cubic Bezier.
 *
 * When either sum is too short (its squared length is below MIN_DIR_LEN_SQ) the function returns and leaves
 * out unchanged.  lo, hi, ia and ib (the point indices) are not used.
 */
void func_020a6f80(Spline *self, Vec3 *out, Fx t, Vec3 *a, Vec3 *b, Vec3 *pa, Vec3 *pb, s32 lo, s32 hi, s32 ia, s32 ib) {
    Vec3 d1;
    Vec3 d2;
    Vec3 tan1;
    Vec3 d3;
    Vec3 d4;
    Fx r1;
    s32 len2;
    Vec3 tan2;
    Fx s1;
    s32 u;
    s32 c1z;
    s32 c1y;
    s32 c1x;
    Fx r2;
    s32 len1;
    Fx s2;
    Vec3 c2;

    u = FX_ONE - t.v;

    /* tangent and control point at b */
    vec_sub(b, a, &d1);
    vec_sub(b, pa, &d2);
    len1 = vec_mag(&d1);
    vec_unit(&d1);
    vec_unit(&d2);
    vec_add(&d1, &d2, &tan1);
    func_020111c4(&r1, &tan1);
    if (fx_val(&r1) < MIN_DIR_LEN_SQ) {
        return;
    }
    if (func_020a8214(self, a, b, pa)) {
        vec_rot_y(&tan1, data_020f98c4);
    } else {
        vec_rot_y(&tan1, data_020fb8c4);
    }
    vec_unit(&tan1);
    len1 = FX_Div(len1, self->f2d8);
    s1.v = fx_mul(len1, self->f2dc);
    vec_scale(&tan1, &s1);
    c1z = tan1.z + b->z;
    c1y = tan1.y + b->y;
    c1x = tan1.x + b->x;

    /* tangent and control point at a */
    vec_sub(a, pb, &d3);
    vec_sub(a, b, &d4);
    len2 = vec_mag(&d4);
    vec_unit(&d3);
    vec_unit(&d4);
    vec_add(&d3, &d4, &tan2);
    func_020111c4(&r2, &tan2);
    if (fx_val(&r2) < MIN_DIR_LEN_SQ) {
        return;
    }
    if (func_020a8214(self, pb, a, b)) {
        vec_rot_y(&tan2, data_020fb8c4);
    } else {
        vec_rot_y(&tan2, data_020f98c4);
    }
    vec_unit(&tan2);
    len2 = FX_Div(len2, self->f2d8);
    s2.v = fx_mul(len2, self->f2dc);
    vec_scale(&tan2, &s2);
    vec_add(&tan2, a, &c2);

    out->x = bez(&a->x, &c1x, &b->x, &c2.x, u, t.v);
    out->y = bez(&a->y, &c1y, &b->y, &c2.y, u, t.v);
    out->z = bez(&a->z, &c1z, &b->z, &c2.z, u, t.v);
}
