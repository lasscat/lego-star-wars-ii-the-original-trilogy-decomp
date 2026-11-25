#include "m2c.h"

// NDS hardware divider / square-root unit (ARM9 I/O registers).
enum {
    REG_DIVCNT      = 0x4000280,
    REG_DIV_NUMER   = 0x4000290,
    REG_DIV_DENOM   = 0x4000298,
    REG_DIV_RESULT  = 0x40002A0,
    REG_SQRTCNT     = 0x40002B0,
    REG_SQRT_RESULT = 0x40002B4,
    REG_SQRT_PARAM  = 0x40002B8
};

enum {
    DIV_MODE_64_64 = 2,
    SQRT_MODE_64   = 1,
    MATH_BUSY      = 0x8000
};

// 20.12 fixed point.
enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800,
    FX_ONE   = 0x1000,
    FX_TWO   = 0x2000
};

// Squared length (20.12) below which the sum of the two unit vectors is treated as zero.
enum {
    MIN_DIR_LEN_SQ = 0x10
};

extern "C" {

typedef struct {
    s32 x, y, z;
} Vec3;

typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

// Replacement for a zero vector in vec_normalize.
extern const Vec3 data_020ff9b4;
// {sin, cos} pairs of the 4096-entry table at data_020f88c4.
extern const s16 data_020f98c4[2]; // entry 0x400: 90 degrees
extern const s16 data_020fb8c4[2]; // entry 0xc00: 270 degrees

// 20.12 fixed-point value.
class Fx {
public:
    s32 v;

    Fx() {}
    Fx(s32 x) :
        v(x) {}
    operator s32() const {
        return v;
    }
};

// Returns 1 when the X/Z cross product (c - a) x (c - b) is positive; the first argument is unused.
s32 func_020a8214(void *, Vec3 *a, Vec3 *b, Vec3 *c);
// Squared length of a vector (20.12).
Fx func_020111c4(const Vec3 *);
s32 FX_Div(s32, s32);

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

static inline void vec_sub(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    Vec3 t;
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    t.x   = x;
    t.y   = y;
    t.z   = z;
    vec_set(d, &t);
}

static inline void vec_diff(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline void vec_add(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    Vec3 t;
    s32 z = a->z + b->z;
    s32 y = a->y + b->y;
    s32 x = a->x + b->x;
    t.x   = x;
    t.y   = y;
    t.z   = z;
    vec_set(d, &t);
}

static inline s64 vec_mag_sq(const Vec3 *p) {
    s64 r = (s64) p->x * p->x;
    r += (s64) p->y * p->y;
    r += (s64) p->z * p->z;
    return r;
}

// Length from the hardware square root, taken with one extra bit and rounded.
static inline s32 vec_mag(const Vec3 *v) {
    s64 t                     = vec_mag_sq(v);
    (*(vu16 *) REG_SQRTCNT)   = SQRT_MODE_64;
    (*(u64 *) REG_SQRT_PARAM) = t << 2;
    while ((*(vu16 *) REG_SQRTCNT) & MATH_BUSY) {
    }
    return (s32) ((*(vu32 *) REG_SQRT_RESULT) + 1) >> 1;
}

// Scales v to unit length: 2^56 / |v|^2 on the divider times |v| from the square-root unit.
static inline void vec_normalize(Vec3 *v) {
    s64 t;
    s32 sqrt;
    s64 div;

    if (v->x == 0 && v->y == 0 && v->z == 0) {
        vec_set(v, &data_020ff9b4);
        return;
    }
    t = vec_mag_sq(v);

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

    v->x = (s32) ((div * v->x + (1LL << 44)) >> 45);
    v->y = (s32) ((div * v->y + (1LL << 44)) >> 45);
    v->z = (s32) ((div * v->z + (1LL << 44)) >> 45);
}

static inline s32 fx_mulw(s32 a, Fx b) {
    return (s32) (((s64) a * b + FX_HALF) >> FX_SHIFT);
}

static inline void vec_scale_x(Vec3 *v, const Fx &s) {
    v->x = fx_mulw(v->x, s);
}

static inline void vec_scale_xy(Vec3 *v, const Fx &s) {
    vec_scale_x(v, s);
    v->y = fx_mulw(v->y, s);
}

static inline void vec_scale(Vec3 *v, const Fx &s) {
    vec_scale_xy(v, s);
    v->z = fx_mulw(v->z, s);
}

// Rotates v about the Y axis; sc is a {sin, cos} table entry.
static inline void vec_rot_y(Vec3 *v, const s16 *sc) {
    s32 x = v->x;
    s32 z = v->z;
    s32 s = sc[0];
    s32 c = sc[1];
    Fx t;

    t    = fx_mul(z, s);
    v->x = fx_mul(x, c) + t;
    t    = fx_mul(x, s);
    v->z = fx_mul(z, c) - t;
}

// One coordinate of a quadratic Bezier: a * u^2 + 2 * p * t * u + b * t^2, with u = 1 - t.
static inline s32 bezier(s32 a, s32 p, s32 b, s32 t, s32 u) {
    Fx au;
    Fx bt;
    s32 x;

    au = fx_mul(a, u);
    bt = fx_mul(b, t);
    x  = fx_mul(bt, t) + fx_mul(fx_mul(fx_mul(p, FX_TWO), t), u);
    return x + fx_mul(au, u);
}

// Point at parameter t (20.12) of the curved path edge from a to b, used by func_020a6cac when only one
// neighbouring path point pa is available. ia is the path index of pa and lo the lower index of the edge:
// ia < lo means pa lies before a, otherwise it lies after b.
// The Bezier control point is the end of the edge that touches pa, moved along the bisector of the two
// edges there. The bisector is turned by 90 or 270 degrees according to the bend direction, so it is
// perpendicular in X/Z. The offset is the edge length divided by the field at 0x2d8 and multiplied by the
// field at 0x2dc. out is left unchanged when the two unit vectors cancel out. hi is not used.
void func_020a827c(void *self, Vec3 *out, Fx t, Vec3 *a, Vec3 *b, Vec3 *pa, u8 lo, u8 hi, u8 ia) {
    Vec3 d0;
    Vec3 d1;
    Vec3 sum;
    Vec3 dir;
    Vec3 pos;
    s32 len;
    s32 u;
    s32 k;

    vec_diff(&d0, b, a);
    u = FX_ONE - t.v;
    vec_diff(&d1, b, pa);
    len   = vec_mag(&d0);
    sum.x = 0;
    sum.y = 0;
    sum.z = 0;
    dir.x = 0;
    dir.y = 0;
    dir.z = 0;

    if (ia < lo) {
        vec_sub(&d0, a, b);
        vec_sub(&d1, a, pa);
        len = vec_mag(&d0);
        vec_normalize(&d0);
        vec_normalize(&d1);
        vec_add(&sum, &d0, &d1);
        vec_set(&dir, &sum);
        if (func_020111c4(&dir) < MIN_DIR_LEN_SQ) {
            return;
        }
        if (func_020a8214(self, pa, a, b)) {
            vec_rot_y(&dir, data_020fb8c4);
        } else {
            vec_rot_y(&dir, data_020f98c4);
        }
    } else {
        vec_normalize(&d0);
        vec_normalize(&d1);
        vec_add(&sum, &d0, &d1);
        vec_set(&dir, &sum);
        if (func_020111c4(&dir) < MIN_DIR_LEN_SQ) {
            return;
        }
        if (func_020a8214(self, a, b, pa)) {
            vec_rot_y(&dir, data_020f98c4);
        } else {
            vec_rot_y(&dir, data_020fb8c4);
        }
    }
    // Control point = end point + dir * (edge length / self[0x2d8] * self[0x2dc]).
    vec_normalize(&dir);
    k = FX_Div(len, *(s32 *) ((u8 *) self + 0x2d8));
    k = fx_mul(k, *(s32 *) ((u8 *) self + 0x2dc));
    vec_scale(&dir, k);
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    vec_add(&pos, &dir, b);
    if (ia < lo) {
        vec_add(&pos, &dir, a);
    }
    out->x = bezier(a->x, pos.x, b->x, t.v, u);
    out->y = bezier(a->y, pos.y, b->y, t.v, u);
    out->z = bezier(a->z, pos.z, b->z, t.v, u);
}
}
