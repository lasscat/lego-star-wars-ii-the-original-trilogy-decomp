#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} Fx32;

typedef struct {
    u16 v;
} Ang;

typedef struct {
    Ang x;
    Ang y;
    Ang z;
} Rot;

typedef struct {
    s32 x;
    s32 y;
} Vec2;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad34[0x40 - 0x34];
    Rot rot;
    u8 pad46[0x48 - 0x46];
    u8 rot_dirty;
    u8 pos_dirty;
    u8 pad4a[0x2c8 - 0x4a];
    s32 max_speed;
    s32 look_scale;
    s32 orbit_scale;
    u8 pad2d4[0x2ea - 0x2d4];
    Rot new_rot;
    u8 pad2f0[0x2f4 - 0x2f0];
    Fx32 speed;
    u8 orbit;
    u8 pad2f9[0x2fc - 0x2f9];
    Vec2 cur;
    Vec2 input;
} Obj;

extern s32 FX_Sqrt(s32);
extern s32 FX_Div(s32, s32);
extern void func_02007f24(Fx32 *, double);
extern void func_020a9634(Obj *, Vec3 *);
extern void func_020aa76c(Obj *, Vec3 *);
extern const s16 data_020f88c4[];

// 20.12 fixed point: 0x1000 is 1.0, 0x800 rounds the product.
enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800,
    FX_ONE   = 0x1000
};

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_HALF) >> FX_SHIFT);
}

static inline s32 fx_mul_wide(s32 a, s32 b) {
    s64 t = (s64) a * b;
    t     = (t + FX_HALF) >> FX_SHIFT;
    return (s32) t;
}

static inline s32 fx_mul_own(s32 a, s32 b) {
    a = (s32) (((s64) a * b + FX_HALF) >> FX_SHIFT);
    return a;
}

static inline s32 fx_sqrt(Fx32 a) {
    return FX_Sqrt(a.v);
}

static inline Fx32 fx_make(s32 v) {
    Fx32 r;
    r.v = v;
    return r;
}

static inline Fx32 fx_inv(s32 v) {
    return fx_make(FX_Div(FX_ONE, v));
}

static inline Fx32 fx_len2(s32 x, const s32 *y) {
    Fx32 r;
    r.v = fx_mul(x, x) + fx_mul(*y, *y);
    return r;
}

static inline s32 pair_len(s32 x, const s32 *y) {
    return fx_sqrt(fx_len2(x, y));
}

static inline s32 pair_len_local(s32 x, const s32 *y) {
    Fx32 sum;
    Fx32 arg;
    sum.v = fx_mul(x, x) + fx_mul(*y, *y);
    arg   = sum;
    return FX_Sqrt(arg.v);
}

static inline void pair_set(s32 *x, s32 *y, s32 a, s32 b) {
    *x = a;
    *y = b;
}

static inline void pair_scale(s32 *x, s32 *y, Fx32 k) {
    Fx32 ky;
    *x = fx_mul(*x, k.v);
    ky = k;
    *y = fx_mul(*y, ky.v);
}

static inline void pair_mul(s32 *x, s32 *y, const Fx32 *k) {
    Fx32 kx;
    Fx32 ky;
    kx = *k;
    ky = *k;
    *x = fx_mul(*x, kx.v);
    *y = fx_mul(*y, ky.v);
}

static inline void pair_mul_by(s32 *x, s32 *y, const Fx32 *k) {
    pair_mul(x, y, k);
}

static inline void ang_set(Ang *d, Ang s) {
    d->v = s.v;
}

static inline void rot_set(Rot *d, const Rot *s) {
    ang_set(&d->x, s->x);
    ang_set(&d->y, s->y);
    ang_set(&d->z, s->z);
}

static inline const Ang *ang_copy(Ang *d, const Ang *s) {
    d->v = s->v;
    return d;
}

static inline int ang_eq(const Ang *a, const Ang *b) {
    return a->v == b->v;
}

static inline void ang_assign(Ang *d, const Ang *s) {
    d->v = s->v;
}

static inline int rot_eq(const Rot *a, const Rot *b) {
    Ang x;
    Ang y;
    Ang z;
    return ang_eq(&a->x, ang_copy(&x, &b->x)) && ang_eq(&a->y, ang_copy(&y, &b->y)) && ang_eq(&a->z, ang_copy(&z, &b->z));
}

static inline int rot_ne(const Rot *a, const Rot *b) {
    return !rot_eq(a, b);
}

static inline void rot_assign(Rot *d, const Rot *s) {
    Ang x;
    Ang y;
    Ang z;
    ang_assign(&d->x, ang_copy(&x, &s->x));
    ang_assign(&d->y, ang_copy(&y, &s->y));
    ang_assign(&d->z, ang_copy(&z, &s->z));
}

static inline void obj_commit_rot(Obj *self) {
    if (rot_ne(&self->new_rot, &self->rot)) {
        rot_assign(&self->rot, &self->new_rot);
        self->rot_dirty = 1;
    }
}

// Fixed-point degrees to a 16-bit angle: 0xB60B60B60B / 2^32 is 65536 / 360.
static inline u16 deg_to_ang(s32 d) {
    return (u16) (((s64) d * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
}

// data_020f88c4 holds (sin, cos) pairs, one pair per 16 angle units.
static inline s32 sin_of(u16 a) {
    return data_020f88c4[(a >> 4) * 2];
}

static inline s32 cos_of(u16 a) {
    return data_020f88c4[(a >> 4) * 2 + 1];
}

static inline void ang_dec(Ang *d, Ang b) {
    Ang r;
    Ang t;
    r.v = d->v - b.v;
    t   = r;
    ang_set(d, t);
}

static inline void turn(Ang *d, const Ang *b) {
    ang_dec(d, *b);
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_rotz(Vec3 *v, u16 a) {
    s32 s = sin_of(a);
    s32 c = cos_of(a);
    s32 x = v->x;
    s32 y = v->y;
    s32 n;
    s32 u;
    s64 t;
    t = y;
    t = (t * s + FX_HALF) >> FX_SHIFT;
    u = (s32) t;
    n = fx_mul(x, c);
    n -= u;
    v->x = n;
    t    = x;
    t    = (t * s + FX_HALF) >> FX_SHIFT;
    n    = fx_mul_wide(y, c);
    v->y = n + (s32) t;
}

static inline void vec_roty(Vec3 *v, u16 a) {
    s64 s = sin_of(a);
    s32 c = cos_of(a);
    s32 x = v->x;
    s64 z = v->z;
    s32 n;
    s32 t;
    t = (s32) ((z * s + FX_HALF) >> FX_SHIFT);
    n = fx_mul(x, c);
    n += t;
    v->x = n;
    t    = (s32) ((x * s + FX_HALF) >> FX_SHIFT);
    t    = fx_mul(z, c) - t;
    v->z = t;
}

// Moves cur towards input, limited by a speed that grows by 0.5 up to max_speed, and turns new_rot by the
// scaled offset. With orbit set, rotates pos about the pivot from func_020aa76c by the input angles.
// Clears input at the end.
void func_020a0ec4(Obj *self) {
    s32 dx;
    s32 dy;
    s32 len;
    Ang yaw;
    Ang pitch;

    rot_set(&self->new_rot, &self->rot);

    pair_set(&dx, &dy, self->input.x - self->cur.x, self->input.y - self->cur.y);
    len = pair_len_local(dx, &dy);
    if (len != 0) {
        Fx32 accel;
        s32 speed;
        func_02007f24(&accel, 0.5);
        speed         = self->speed.v + accel.v;
        self->speed.v = speed;
        if (speed >= self->max_speed) {
            self->speed.v = self->max_speed;
        }
        if (len > self->speed.v) {
            s32 l = pair_len(dx, &dy);
            if (l > 0) {
                pair_scale(&dx, &dy, fx_inv(l));
            } else {
                dx = 0;
                dy = 0;
            }
            pair_mul_by(&dx, &dy, &self->speed);
        } else {
            self->speed.v = 0;
        }
    }
    self->cur.x += dx;
    self->cur.y += dy;

    yaw.v = deg_to_ang(fx_mul_wide(self->cur.x, self->look_scale));
    turn(&self->new_rot.y, &yaw);
    pitch.v = deg_to_ang(fx_mul_wide(self->cur.y, self->look_scale));
    turn(&self->new_rot.x, &pitch);
    if (self->orbit == 0) {
        obj_commit_rot(self);
    } else {
        Vec3 pivot;
        Vec3 np;
        Vec3 r;
        pivot.x = 0;
        pivot.y = 0;
        pivot.z = 0;
        func_020aa76c(self, &pivot);
        r.z = self->pos.z;
        r.z -= pivot.z;
        r.y = self->pos.y - pivot.y;
        r.x = self->pos.x - pivot.x;
        vec_rotz(&r, deg_to_ang(fx_mul(self->input.y, self->orbit_scale)));
        vec_roty(&r, deg_to_ang(fx_mul_own(self->input.x, self->orbit_scale)));
        np.x = pivot.x + r.x;
        np.y = pivot.y + r.y;
        np.z = pivot.z + r.z;
        if (vec_ne(&self->pos, &np)) {
            vec_set(&self->pos, &np);
            self->pos_dirty = 1;
        }
        func_020a9634(self, &self->pos);
    }
    self->input.x = 0;
    self->input.y = 0;
}
