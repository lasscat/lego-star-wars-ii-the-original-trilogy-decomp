#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u16 v;
} Angle;

typedef struct {
    Angle x;
    Angle y;
    Angle z;
} Rot;

typedef struct {
    Angle x;
    Angle y;
    Angle z;
    u16 pad;
} Rot3;

typedef struct {
    Vec3s pos;
    s16 rot[3];
} PathNode;

typedef struct {
    u8 pad00[0x28];
    Vec3 pos;
    u8 pad34[0x40 - 0x34];
    Rot3 rot;
    u8 rotDirty;
    u8 posDirty;
    u8 pad4a[0x21c - 0x4a];
    void *points;
    u8 pad220[0x230 - 0x220];
    Vec3 target;
    u8 hasTarget;
    u8 pad23d[0x2e1 - 0x23d];
    u8 lastIdx;
    u8 idx;
    u8 pad2e3;
    s32 speed;
    u8 forward;
    u8 b2e9;
} Obj;

PathNode *func_02067b48(void *, s32);
PathNode *func_020a51cc(Obj *);
void func_020675d8(void *, s32);
s32 FX_Div(s32, s32);

enum {
    FX32_SHIFT      = 12, /* 20.12 fixed point */
    FX32_HALF       = 0x800,
    REG_DIVCNT      = 0x04000280,
    REG_DIV_NUMER   = 0x04000290,
    REG_DIV_DENOM   = 0x04000298,
    REG_DIV_RESULT  = 0x040002a0,
    REG_SQRTCNT     = 0x040002b0,
    REG_SQRT_RESULT = 0x040002b4,
    REG_SQRT_PARAM  = 0x040002b8,
    MATH_BUSY       = 0x8000
};

extern Vec3 data_020ff9b4;
extern u8 data_0210930c[];

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX32_HALF) >> FX32_SHIFT);
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_sub(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline s32 fx_mul64(s32 a, s32 b) {
    s64 t = (s64) a * b;
    t += FX32_HALF;
    t >>= FX32_SHIFT;
    return (s32) t;
}

static inline void vec_mul_add(Vec3 *d, const Vec3 *v, s32 s) {
    s64 z = fx_mul64(v->z, s);
    s64 y = fx_mul64(v->y, s);
    s64 x = fx_mul64(v->x, s);
    x     = d->x + (s32) x;
    y     = d->y + (s32) y;
    z     = d->z + (s32) z;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline s32 vec_mag(const Vec3 *v) {
    s64 t = (s64) v->x * v->x;
    t += (s64) v->y * v->y;
    t += (s64) v->z * v->z;
    *(volatile u16 *) REG_SQRTCNT = 1;
    *(u64 *) REG_SQRT_PARAM       = t << 2;
    while (*(volatile u16 *) REG_SQRTCNT & MATH_BUSY) {
    }
    return (*(volatile s32 *) REG_SQRT_RESULT + 1) >> 1;
}

static inline void fx_sub(s32 *d, s32 a, s32 b) {
    a -= b;
    *d = a;
}

static inline void vec_normalize(const Vec3 *s, Vec3 *d) {
    s64 t = (s64) s->x * s->x;
    s32 r;
    t += (s64) s->y * s->y;
    t += (s64) s->z * s->z;
    *(volatile u16 *) REG_DIVCNT    = 2;
    *(volatile s64 *) REG_DIV_NUMER = 0x0100000000000000LL;
    *(volatile s64 *) REG_DIV_DENOM = t;
    *(volatile u16 *) REG_SQRTCNT   = 1;
    *(u64 *) REG_SQRT_PARAM         = t << 2;
    while (*(volatile u16 *) REG_SQRTCNT & MATH_BUSY) {
    }
    r = *(volatile s32 *) REG_SQRT_RESULT;
    while (*(volatile u16 *) REG_DIVCNT & MATH_BUSY) {
    }
    t = *(volatile s64 *) REG_DIV_RESULT;
    t *= r;
    d->x = (s32) ((t * s->x + (1LL << 44)) >> 45);
    d->y = (s32) ((t * s->y + (1LL << 44)) >> 45);
    d->z = (s32) ((t * s->z + (1LL << 44)) >> 45);
}

static inline void vec_dir(Vec3 *d) {
    if (d->x == 0 && d->y == 0 && d->z == 0) {
        vec_set(d, &data_020ff9b4);
    } else {
        vec_normalize(d, d);
    }
}

/* Node positions are whole units; widen them to 20.12 fixed point. */
static inline Vec3 *node_pos(Vec3 *d, const Vec3s *s) {
    s32 z = s->z << FX32_SHIFT;
    s32 y = s->y << FX32_SHIFT;
    s32 x = s->x << FX32_SHIFT;
    d->x  = x;
    d->y  = y;
    d->z  = z;
    return d;
}

static inline void angle_set(Angle *d, Angle s) {
    u16 v = s.v;
    d->v  = v;
}

static inline void angle_put(Angle *d, Angle s) {
    int v = s.v;
    d->v  = v;
}

static inline int angle_eq(const Angle *a, Angle b) {
    return a->v == b.v;
}

/* 20.12 radians to a 16-bit angle (0x10000 = a full turn); the scale has 44 fraction bits. */
static inline void angle_from_rad(Angle *a, s32 rad) {
    rad  = (s32) (((s64) rad * 0x28BE60DB9391LL + 0x80000000000LL) >> 44);
    a->v = rad;
}

static inline void angle_from_rad_direct(Angle *a, s32 rad) {
    a->v = (s32) (((s64) rad * 0x28BE60DB9391LL + 0x80000000000LL) >> 44);
}

static inline void node_rot(Rot *r, const PathNode *n) {
    Angle x, y, z;
    angle_from_rad(&z, n->rot[0]);
    angle_set(&r->z, z);
    angle_from_rad(&y, n->rot[1]);
    angle_set(&r->y, y);
    angle_from_rad(&x, n->rot[2]);
    angle_set(&r->x, x);
}

static inline void node_rot_cur(Rot *r, const PathNode *n) {
    Angle x, y, z;
    angle_from_rad(&z, n->rot[0]);
    angle_put(&r->z, z);
    angle_from_rad(&y, n->rot[1]);
    angle_put(&r->y, y);
    angle_from_rad_direct(&x, n->rot[2]);
    angle_put(&r->x, x);
}

static inline void node_rot_next(Rot *r, const PathNode *n) {
    Angle x, y, z;
    angle_from_rad_direct(&z, n->rot[0]);
    angle_set(&r->z, z);
    angle_from_rad_direct(&y, n->rot[1]);
    angle_set(&r->y, y);
    angle_from_rad_direct(&x, n->rot[2]);
    angle_set(&r->x, x);
}

static inline void rot_set3(Rot3 *d, Angle x, Angle y, Angle z) {
    d->x.v = x.v;
    d->y.v = y.v;
    d->z.v = z.v;
}

/* The destination x, y, z take the source y, z, x. */
static inline void rot_swizzle(Rot3 *d, const Rot *s) {
    rot_set3(d, s->y, s->z, s->x);
}

static inline void angle_diff(Angle *d, const Angle *a, const Angle *b) {
    d->v = a->v - b->v;
}

static inline void rot_sub3(Rot *d, const Rot *a, Angle z, Angle y, Angle x) {
    angle_diff(&d->x, &a->x, &x);
    angle_diff(&d->z, &a->z, &z);
    angle_diff(&d->y, &a->y, &y);
}

static inline void rot_sub(Rot *d, const Rot *a, const Rot *b) {
    rot_sub3(d, a, b->z, b->y, b->x);
}

static inline Angle angle_mul(Angle *d, s32 t, u16 v) {
    int s = (s16) v;
    s     = fx_mul(t, s);
    d->v  = s;
    return *d;
}

static inline void angle_add(Angle *d, const Angle *a, const Angle *b) {
    u16 v = a->v;
    v += b->v;
    d->v = v;
}

static inline void rot_add3(Rot3 *d, const Rot *a, Angle x, Angle y, Angle z) {
    angle_add(&d->x, &a->y, &x);
    angle_add(&d->y, &a->z, &y);
    angle_add(&d->z, &a->x, &z);
}

static inline void rot_lerp(Rot3 *d, const Rot *a, s32 t, const Rot *delta) {
    Angle z, y, x;
    rot_add3(d, a, angle_mul(&x, t, delta->y.v), angle_mul(&y, t, delta->z.v), angle_mul(&z, t, delta->x.v));
}

/* Store the rotation and flag it dirty only when it changed. */
static inline void sync_ang(Obj *o, const Rot3 *a) {
    int e;
    int f;
    f = 0;
    e = 0;
    if (angle_eq(&a->x, o->rot.x)) {
        if (angle_eq(&a->y, o->rot.y)) {
            e = 1;
        }
    }
    if (e) {
        if (angle_eq(&a->z, o->rot.z)) {
            f = 1;
        }
    }
    if (!f) {
        angle_set(&o->rot.x, a->x);
        angle_set(&o->rot.y, a->y);
        angle_set(&o->rot.z, a->z);
        o->rotDirty = 1;
    }
}

static inline void sync_ang_t(Obj *o, const Rot3 *a) {
    Angle cx, cy, cz, sx, sy, sz;
    int e;
    int f;
    f  = 0;
    e  = 0;
    cx = o->rot.x;
    if (a->x.v == cx.v) {
        cy = o->rot.y;
        if (a->y.v == cy.v) {
            e = 1;
        }
    }
    if (e) {
        cz = o->rot.z;
        if (a->z.v == cz.v) {
            f = 1;
        }
    }
    if (!f) {
        sx          = a->x;
        o->rot.x.v  = sx.v;
        sy          = a->y;
        o->rot.y.v  = sy.v;
        sz          = a->z;
        o->rot.z.v  = sz.v;
        o->rotDirty = 1;
    }
}

static inline void obj_sync_rot(Obj *o, const Rot3 *r) {
    sync_ang_t(o, r);
}

/*
 * Advance an object along its list of path nodes. The position moves toward the current target by at
 * most `speed`; on arrival the node index steps forward or backward (towards lastIdx) and the next
 * node is fetched. With no next node or no target yet, the object takes the current node's position
 * and rotation; otherwise its rotation is interpolated between the current and next nodes by the
 * ratio of the distances (node to position) / (node to next). The next node becomes the new target.
 */
void func_020a486c(Obj *self) {
    Vec3 pos;
    Vec3 d;
    Vec3 p0;
    Vec3 q;
    Rot3 r2;
    Rot3 r1;
    PathNode *next;
    PathNode *node;

    pos.x = self->pos.x;
    pos.y = self->pos.y;
    pos.z = self->pos.z;
    next  = func_020a51cc(self);
    node  = func_02067b48(self->points, self->idx);
    if (self->hasTarget) {
        vec_sub(&d, &self->target, &pos);
        if (self->speed >= vec_mag(&d)) {
            vec_set(&pos, &self->target);
            if (self->forward && self->idx < self->lastIdx) {
                self->idx++;
                node = func_02067b48(self->points, self->idx);
                next = func_020a51cc(self);
            } else if (!self->forward && self->idx > self->lastIdx) {
                self->idx--;
                node = func_02067b48(self->points, self->idx);
                next = func_020a51cc(self);
            }
        } else {
            vec_dir(&d);
            vec_mul_add(&pos, &d, self->speed);
        }
    }
    if (next == NULL || !self->hasTarget) {
        Rot p;
        Rot3 *pr;
        node_rot(&p, node);
        vec_set(&pos, node_pos(&p0, &node->pos));
        pr = &r1;
        rot_swizzle(pr, &p);
        sync_ang(self, pr);
        if (next == NULL) {
            func_020675d8(*(u8 **) (*(u8 **) (*(u8 **) (data_0210930c + 0x68) + 0x38c) + 4) + 0x28, self->b2e9);
            self->b2e9 = 0;
        }
    } else {
        Vec3 a, b;
        Vec3 da, db;
        s32 t;
        Rot pb, pa, qb;
        Rot3 *pr;
        node_pos(&a, &node->pos);
        node_pos(&b, &next->pos);
        fx_sub(&da.z, a.z, b.z);
        fx_sub(&da.x, a.x, b.x);
        fx_sub(&da.y, a.y, b.y);
        fx_sub(&db.z, a.z, pos.z);
        fx_sub(&db.y, a.y, pos.y);
        fx_sub(&db.x, a.x, pos.x);
        {
            s32 den = vec_mag(&da);
            t       = FX_Div(vec_mag(&db), den);
        }
        node_rot_cur(&pa, node);
        node_rot_next(&pb, next);
        rot_sub(&qb, &pa, &pb);
        rot_lerp(&r2, &pa, t, &qb);
        pr = &r2;
        obj_sync_rot(self, pr);
    }
    if (next != NULL) {
        vec_set(&self->target, node_pos(&q, &next->pos));
        self->hasTarget = 1;
    } else {
        self->hasTarget = 0;
    }
    if (vec_ne(&self->pos, &pos)) {
        vec_set(&self->pos, &pos);
        self->posDirty = 1;
    }
}
