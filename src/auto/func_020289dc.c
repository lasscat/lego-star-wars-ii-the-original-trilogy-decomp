#include "m2c.h"

typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef struct {
    u16 v;
} H;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} Vec3;

typedef struct {
    H x;
    H y;
    H z;
} Rot3;

/* 0x28-byte slot at +0x1bc: scale (Vec3, set by func_0200c9e4), rotation at
 * +0x1c8, dirty flag at +0x1ce (same layout as in func_02028f04). */
typedef struct {
    u8 pad0[0x1c8];
    Rot3 rot;
    u16 dirty;
} Node;

typedef struct {
    u8 flag;
    u8 pad1[0x37];
} Body;

typedef struct {
    u8 *w;
    s32 idx;
    u32 *link;
    u32 pad0c;
    u32 pad10;
    u32 pad14;
    u32 pad18;
    s32 count;
} Ctl;

extern void func_0200c9e4(u8 *, s32, Vec3 *);
extern s32 func_02027f68(void *);
extern void func_02028be8(Ctl *);
extern void func_02028ea8(Ctl *, u8 *, void *);
extern void func_0202934c(Vec3 *, void *);
extern s16 func_020985d8(s32, s32);

/* fx32 fixed point (12 fraction bits): 1.0 and 2.0. */
enum {
    FX32_ONE = 0x1000,
    FX32_TWO = 0x2000
};

/* NDS hardware square-root unit. */
enum {
    REG_SQRTCNT        = 0x040002b0,
    REG_SQRT_RESULT    = 0x040002b4,
    REG_SQRT_PARAM     = 0x040002b8,
    SQRTCNT_MODE_64BIT = 1,
    SQRTCNT_BUSY       = 0x8000
};

/* Same helper as in func_02028be8.c: 64-bit input v << 2, wait for the busy
 * bit, round with (r + 1) >> 1. */
static inline s32 fx_sqrt(s64 v) {
    *(vu16 *) REG_SQRTCNT   = SQRTCNT_MODE_64BIT;
    *(u64 *) REG_SQRT_PARAM = v << 2;
    while (*(vu16 *) REG_SQRTCNT & SQRTCNT_BUSY) {
    }
    return ((s32) * (vu32 *) REG_SQRT_RESULT + 1) >> 1;
}

/* c->link points 4 bytes into the linked entity. */
static inline void *linked(Ctl *c) {
    u8 *e = (u8 *) c->link;
    if (e) {
        e = e - 4;
    }
    return e;
}

static inline Vec3 *vec_sub(Vec3 *o, const Vec3 *p, const Vec3 *q) {
    s32 x, y, z;
    z = p->z.v;
    z -= q->z.v;
    y = p->y.v;
    y -= q->y.v;
    x = p->x.v;
    x -= q->x.v;
    o->x.v = x;
    o->y.v = y;
    o->z.v = z;
    return o;
}

static inline Vec3 *get_pos(Vec3 *o, void *e) {
    func_0202934c(o, e);
    return o;
}

static inline s32 vec_mag(const Vec3 *v) {
    s64 t = (s64) v->x.v * v->x.v;
    t += (s64) v->y.v * v->y.v;
    t += (s64) v->z.v * v->z.v;
    return fx_sqrt(t);
}

/* out = -atan2(v.y, sqrt(v.x * v.x + v.z * v.z)), as in func_02028be8.c. */
static inline void calc_pitch(H *out, const Vec3 *v) {
    Fx y;
    s32 r;
    s64 t = (s64) v->x.v * v->x.v;
    t += (s64) v->z.v * v->z.v;
    r      = fx_sqrt(t);
    y      = v->y;
    out->v = -(u16) func_020985d8(y.v, r);
}

/* Writes |v| to *out. */
static inline void vec_mag_to(Fx *out, const Vec3 *v) {
    out->v = vec_mag(v);
}

static inline void vec_set3(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x.v = x;
    v->y.v = y;
    v->z.v = z;
}

static inline Node *node_of(Ctl *c) {
    return (Node *) (c->w + c->idx * 0x28);
}

/* Copies the rotation into the node through a stack copy, field by field, the
 * same way func_02028f04 does it, then marks the node dirty. */
static inline void ctl_set_rot(Ctl *c, const Rot3 *r) {
    Rot3 a;
    Node *n  = node_of(c);
    a.x      = r->x;
    n->rot.x = a.x;
    a.y      = r->y;
    n->rot.y = a.y;
    a.z      = r->z;
    n->rot.z = a.z;
    n->dirty = 1;
}

/*
 * Stretches the node c->idx of c->w between the entity c->w and linked(c).
 * - Returns at once when there is no linked entity.
 * - Decrements c->count, then calls func_02028be8(c) when
 *   func_02027f68(linked(c)) is nonzero, else func_02028ea8(c, c->w, linked(c)).
 * - Returns when the flag byte at +0x3cc of the 0x38-byte entry c->idx is 0.
 * - d = pos(linked(c)) - pos(c->w). Scale = (1.0, 1.0, |d| + 2.0) through
 *   func_0200c9e4; rotation = (-atan2(d.y, sqrt(d.x^2 + d.z^2)), 0, 0).
 */
void func_020289dc(Ctl *c) {
    Vec3 d;
    Vec3 pos[2];
    Vec3 scale;
    Rot3 rot;

    if (linked(c) == 0) {
        return;
    }
    c->count--;
    if (func_02027f68(linked(c)) != 0) {
        func_02028be8(c);
    } else {
        func_02028ea8(c, c->w, linked(c));
    }
    if (((Body *) (c->w + 0x3cc))[c->idx].flag == 0) {
        return;
    }
    func_0202934c(pos, c->w);
    vec_sub(&d, get_pos(pos + 1, linked(c)), pos);
    /* The length is written into scale.z, then the setter builds the whole
     * vector from it: (1.0, 1.0, length + 2.0). */
    vec_mag_to(&scale.z, &d);
    vec_set3(&scale, FX32_ONE, FX32_ONE, scale.z.v + FX32_TWO);
    func_0200c9e4(c->w, c->idx, &scale);
    calc_pitch(&rot.x, &d);
    rot.y.v = 0;
    rot.z.v = 0;
    ctl_set_rot(c, &rot);
}
