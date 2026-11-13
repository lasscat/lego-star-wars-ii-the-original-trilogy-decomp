#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} Scalar;

typedef struct {
    void *vptr;
    Vec3 pos;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    s32 half;
    s32 radius;
} Capsule;

typedef struct {
    void *vptr;
    Vec3 pos;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    s16 h0;
    s16 h1;
    s16 h2;
    s32 w;
} Sphere;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe4a8;

void func_0200af88(s8 *arg0, s8 arg1);
void func_02008f50(Vec3 *out, Scalar y, Vec3 *from, Vec3 dir);
void func_0200913c(Vec3 *out, Vec3 *from, Vec3 dir, Sphere *s);
void func_0204d2a4(Scalar *out, Capsule *c);
void func_0204d2b8(Scalar *out, Capsule *c);
void func_0204f760(Sphere *s, Scalar r);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_set3(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline Vec3 *vec_make(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

enum {
    FX_ONE = 0x1000
};

static inline s32 fx_sq(s32 a) {
    return (s32) (((s64) a * a + 0x800) >> 12);
}

static inline int in_disc(Capsule *c, const Vec3 *v) {
    s32 r = fx_sq(c->radius);
    return fx_sq(v->x) + fx_sq(v->z) <= r;
}

static inline int cap_top(Capsule *c) {
    Scalar t;
    func_0204d2a4(&t, c);
    return t.v;
}

static inline int cap_bottom(Capsule *c) {
    Scalar t;
    func_0204d2b8(&t, c);
    return t.v;
}

static inline void ray_top(Vec3 *hit, Capsule *c, Vec3 *pos, Vec3 *dir) {
    Scalar t;
    func_0204d2a4(&t, c);
    func_02008f50(hit, t, pos, *dir);
}

static inline void ray_bottom(Vec3 *hit, Capsule *c, Vec3 *pos, Vec3 *dir) {
    Scalar t;
    func_0204d2b8(&t, c);
    func_02008f50(hit, t, pos, *dir);
}

static inline void sphere_radius(Sphere *s, s32 r) {
    Scalar t;
    t.v = r;
    func_0204f760(s, t);
}

/* Capsule end-cap test: if pos lies above the top (or below the bottom) of the
 * capsule, out = (0, +-1.0, 0) when pos, or the point where the ray from pos
 * along dir meets that end height, is inside the cap disc (xz distance from
 * the capsule centre <= radius). Otherwise a sphere at the capsule centre with
 * the capsule radius is tested via func_0200913c and its result copied to out.
 */
void func_02009b88(Vec3 *out, Vec3 *pos, Vec3 *dir, Capsule *c) {
    Vec3 d;
    Vec3 hit;
    Vec3 d2;
    Vec3 hit2;
    Sphere s;
    Vec3 up1;
    Vec3 e;
    Vec3 up2;
    Vec3 dn1;
    Vec3 e2;
    Vec3 dn2;
    Vec3 res;

    out->x = 0;
    out->y = 0;
    out->z = 0;
    if (pos->y >= cap_top(c)) {
        s32 x = c->pos.x;
        s32 y;
        s32 z = c->pos.z;

        y = cap_top(c);
        vec_set3(&d, x - pos->x, y - pos->y, z - pos->z);
        if (in_disc(c, &d)) {
            vec_set(out, vec_make(&up1, 0, FX_ONE, 0));
            return;
        }
        ray_top(&hit, c, pos, dir);
        vec_set3(&e, x - hit.x, y - hit.y, z - hit.z);
        vec_set(&d, &e);
        if (in_disc(c, &d)) {
            vec_set(out, vec_make(&up2, 0, FX_ONE, 0));
        }
        return;
    }
    if (pos->y <= cap_bottom(c)) {
        s32 x = c->pos.x;
        s32 y;
        s32 z = c->pos.z;

        y = cap_top(c);
        vec_set3(&d2, x - pos->x, y - pos->y, z - pos->z);
        if (in_disc(c, &d2)) {
            vec_set(out, vec_make(&dn1, 0, -FX_ONE, 0));
            return;
        }
        ray_bottom(&hit2, c, pos, dir);
        vec_set3(&e2, x - hit2.x, y - hit2.y, z - hit2.z);
        vec_set(&d2, &e2);
        if (in_disc(c, &d2)) {
            vec_set(out, vec_make(&dn2, 0, -FX_ONE, 0));
        }
        return;
    }
    s.vptr  = &data_020fcd18;
    s.pos.x = 0;
    s.pos.y = 0;
    s.pos.z = 0;
    s.f10   = 0;
    s.a0    = 0;
    s.a1    = 0;
    s.a2    = 0;
    s.sum   = 0;
    func_0200af88((s8 *) &s.f24[0], -1);
    s.f24[2] = 0;
    s.vptr   = &data_020fe4a8;
    s.h0     = 0;
    s.h1     = 0;
    s.h2     = 0;
    s.w      = 0;
    s.f24[1] = 0;
    vec_set(&s.pos, &c->pos);
    sphere_radius(&s, c->radius);
    func_0200913c(&res, pos, *dir, &s);
    vec_set(out, &res);
}
