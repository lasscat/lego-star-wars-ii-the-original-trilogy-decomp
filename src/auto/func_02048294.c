#include "m2c.h"

typedef struct {
    u16 v;
} HalfVal;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} Vec3;

typedef struct {
    u8 pad0[0x40];
    u8 state;
    u8 pad41[3];
    Vec3 pos;
    u8 pad50[0x10];
    Vec3 vel;
    u8 pad6c[0x44];
    Vec3 goal;
    u8 padbc[0x512];
    u8 path[0xe6];
    HalfVal turn;
} Entity;

typedef struct {
    u8 pad0[0x24];
    Vec3 target;
    u8 pad30[0x15];
    u8 dirty;
} Follower;

typedef struct {
    u8 pad0[4];
    Entity *ent;
    u8 pad8[4];
    u8 flags;
    u8 padd[3];
    Vec3 target;
    u8 timer;
    u8 pad1d[3];
    Follower *follower;
} Obj;

extern u16 func_0204fa30(u8 *);
extern void func_0200d6d0(Vec3 *, const Vec3 *, Fx);
extern void func_020111c4(Fx *, const Vec3 *);
extern s32 func_02018210(Entity *, HalfVal, HalfVal);
extern u8 func_0204a590(void *, HalfVal *);
extern void func_0204a5bc(HalfVal *, void *);
extern s16 func_020985d8(s32, s32);
extern s32 FX_Div(Fx a,
                  s32 b); // FAKE: numerator typed as one-word struct; by-value arg load gives add r0,sp,#0x40; ldr r0,[r0]
extern void func_02007f24(Fx *, double);
extern const s16 data_020f88c4[];

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    if (!(a->x.v == b->x.v && a->y.v == b->y.v && a->z.v == b->z.v)) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void ang_init(HalfVal *h, u16 v) {
    h->v = v;
}

static inline void fx_init(Fx *f, s32 v) {
    f->v = v;
}

static inline void ang_set(HalfVal *d, HalfVal v) {
    d->v = v.v;
}

static inline s16 heading(Fx z, Fx x) {
    return func_020985d8(x.v, z.v);
}

static inline s32 fx_get(const Fx *p) {
    return p->v;
}

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline HalfVal ang_get(const HalfVal *p) {
    return *p;
}

static inline u16 ang_add_v(const HalfVal *a, HalfVal b) {
    HalfVal r;
    r.v = a->v + b.v;
    return ang_get(&r).v;
}

static inline void ang_diff(HalfVal *d, const HalfVal *a, HalfVal b) {
    d->v = a->v - b.v;
}

static inline void vec_setv(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x.v = s->x.v;
        d->y.v = s->y.v;
        d->z.v = s->z.v;
    }
}

static inline void vec_mul3(Vec3 *v, Fx a, Fx b, Fx c) {
    v->x.v = fx_mul(v->x.v, a.v);
    v->y.v = fx_mul(v->y.v, b.v);
    v->z.v = fx_mul(v->z.v, c.v);
}

static inline void follow_set(Follower *f, const Vec3 *g) {
    if (vec_ne(&f->target, g)) {
        vec_setv(&f->target, g);
        f->dirty = 1;
    }
}
/* NDS hardware square-root unit. */
enum {
    REG_SQRTCNT    = 0x040002B0,
    REG_SQRT_RES   = 0x040002B4,
    REG_SQRT_PARAM = 0x040002B8,
    SQRT_MODE_64   = 1,
    SQRT_BUSY      = 0x8000
};

/* Length of v in fx 20.12: sqrt(x*x + y*y + z*z), rounded. */
static inline s32 vec_mag(const Vec3 *v) {
    s64 t;
    t = (s64) v->x.v * v->x.v;
    t += (s64) v->y.v * v->y.v;
    t += (s64) v->z.v * v->z.v;
    *(volatile u16 *) REG_SQRTCNT = SQRT_MODE_64;
    *(u64 *) REG_SQRT_PARAM       = t << 2;
    while (*(volatile u16 *) REG_SQRTCNT & SQRT_BUSY) {
    }
    return ((s32) * (volatile u32 *) REG_SQRT_RES + 1) >> 1;
}

static inline void vec_addv(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    d->x.v = a->x.v + b->x.v;
    d->y.v = a->y.v + b->y.v;
    d->z.v = a->z.v + b->z.v;
}
/* fx 20.12 multiply with rounding. */
static inline s32 fm5(s32 a, s32 b) {
    s64 t = b;
    t     = (a * t + 0x800) >> 12;
    return t;
}
/* Angles are 16-bit binary angles (0x10000 per turn). */
enum {
    ANGLE_10_DEG  = 0x71c,
    ANGLE_60_DEG  = 0x2aaa,
    ANGLE_120_DEG = 0x5555
};

enum {
    TIMER_START = 8,
    LEN_LIMIT   = 0x40
};

/*
 * Per-frame update: refreshes self->target from the entity position (or counts
 * self->timer down and sets flags bit 0 when it runs out), passes the entity goal
 * to the follower, then turns the entity: if the length from func_020111c4 is
 * at least LEN_LIMIT it faces self->target and bends up to +-60 degrees toward
 * the path angle (if within 120 degrees). Finally adds 0.2 along the heading to
 * vel and caps |vel| at 1.25.
 */
void func_02048294(Obj *self) {
    Vec3 flat;
    Fx m;
    Fx zero;
    Fx spd;
    Fx max;
    Fx s;
    Fx t;
    Fx hz;
    Fx hx;
    HalfVal a;
    HalfVal diff;
    HalfVal b1;
    HalfVal step1;
    HalfVal dir;
    HalfVal b2;
    HalfVal lo;
    HalfVal hi;
    HalfVal step2;
    s32 len;
    Entity *e;
    Fx *pm;

    e = self->ent;
    if (e->state != 0 && func_0204fa30(&e->state) == 3) {
        vec_set(&self->target, &self->ent->pos);
        self->timer = TIMER_START;
    } else if (self->ent->state != 0 || --self->timer == 0) {
        self->flags |= 1;
        return;
    }

    if (self->follower != NULL) {
        follow_set(self->follower, &self->ent->goal);
    }

    fx_init(&zero, 0);
    func_0200d6d0(&flat, &self->ent->pos, zero);
    func_020111c4(&m, &flat);
    pm = &m;
    if (pm && pm->v < LEN_LIMIT) { // FAKE: always-true null test keeps &m in a register (add r0,sp,#0x54; ldr r0,[r0])
        if (func_0204a590(self->ent->path, &a)) {
            func_0204a5bc(&b1, self->ent->path);
            a.v = ang_add_v(&a, b1);
            ang_init(&step1, ANGLE_10_DEG);
            func_02018210(self->ent, a, step1);
        }
    } else {
        hz = self->target.z;
        hx = self->target.x;
        ang_init(&dir, heading(hz, hx));
        ang_set(&self->ent->turn, dir);
        if (func_0204a590(self->ent->path, &a)) {
            func_0204a5bc(&b2, self->ent->path);
            a.v = ang_add_v(&a, b2);
            e   = self->ent;
            ang_diff(&diff, &a, e->turn);
            if (((s16) diff.v < 0 ? -(s16) diff.v : (s16) diff.v) < ANGLE_120_DEG) {
                if ((s16) diff.v < -ANGLE_60_DEG) {
                    ang_init(&lo, -ANGLE_60_DEG);
                    ang_set(&diff, lo);
                } else if ((s16) diff.v > ANGLE_60_DEG) {
                    ang_init(&hi, ANGLE_60_DEG);
                    ang_set(&diff, hi);
                }
                e->turn.v = ang_add_v(&e->turn, diff);
            }
        }
        ang_init(&step2, ANGLE_10_DEG);
        func_02018210(self->ent, self->ent->turn, step2);
    }

    func_02007f24(&spd, 0.2);
    {
        /* d = spd along the heading (sin, cos table) in the xz plane. */
        Vec3 d;
        s32 sn = data_020f88c4[(self->ent->turn.v >> 4) * 2];
        s32 cs = data_020f88c4[(self->ent->turn.v >> 4) * 2 + 1];
        d.x.v  = fm5(spd.v, sn);
        d.y.v  = 0;
        d.z.v  = fm5(spd.v, cs);
        e      = self->ent;
        vec_addv(&e->vel, &e->vel, &d);
    }
    len = vec_mag(&self->ent->vel);
    func_02007f24(&max, 1.25);
    if (fx_get(&max) > len) {
        return;
    }
    func_02007f24(&t, 1.25);
    fx_init(&s, FX_Div(t, len));
    e = self->ent;
    vec_mul3(&e->vel, s, s, s);
}
