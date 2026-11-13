#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Half;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad1[0x49 - 0x34];
    u8 f49;
    u8 pad2[0x1d0 - 0x4a];
    s32 f1d0;
    u8 pad3[0x320 - 0x1d4];
    s32 dist;
    s32 dy_out;
    s32 dy_pos;
    Half ang;
    u8 pad4[2];
    s32 dist_min;
    s32 dist_max;
    u8 pad5[0x33c - 0x338];
    u16 step;
} Obj;

typedef struct {
    Half n2;
    Half n2c;
    Half s2;
    Half n1;
    Half n1c;
    Half s1;
} Loc;

extern const s16 data_020f88c4[];
extern u8 data_021027f8[];
u32 func_0205d060(void *, s32, s32);
void func_020a019c(Obj *, Vec3 *);

/* DS divider/sqrt unit registers (hardware memory map). */
enum {
    REG_SQRTCNT = 0x040002b0
};
enum {
    REG_SQRT_PARAM = 0x040002b8
};
enum {
    SQRTCNT_MODE_64BIT = 0x1
};
enum {
    SQRTCNT_BUSY = 0x8000
};

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

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline s16 fx_cos(Half a) {
    return data_020f88c4[(a.v >> 4) * 2 + 1];
}

static inline s16 fx_sin(Half a) {
    return data_020f88c4[(a.v >> 4) * 2];
}

/*
 * Starts and waits for a hardware square root of 4 * (dx * dx + dz * dz)
 * between pos and *p (the result is never read), subtracts step from ang
 * when func_0205d060(data_021027f8, 0x200, 4) returns nonzero, else adds it
 * when func_0205d060(data_021027f8, 0x100, 4) does,
 * clamps dist to [dist_min, dist_max], and sets pos to *p offset by
 * (cos(ang) * dist, dy_pos, sin(ang) * dist), raising f49 when it changes.
 * Finally passes *p with y offset by dy_out to func_020a019c.
 */
void func_020a3a48(Obj *self, Vec3 *p) {
    Vec3 np;
    Vec3 q;
    Loc l;
    s64 t;
    int changed;
    Vec3 tp;

    if (self->f1d0 == 0) {
        return;
    }
    np.x = self->pos.x;
    np.y = self->pos.y;
    np.z = self->pos.z;
    tp.x = p->x;
    tp.y = p->y;
    tp.z = p->z;
    t    = (s64) (np.x - tp.x) * (np.x - tp.x);
    t += (s64) (np.z - tp.z) * (np.z - tp.z);
    t <<= 2;
    *(volatile u16 *) REG_SQRTCNT = SQRTCNT_MODE_64BIT;
    *(u64 *) REG_SQRT_PARAM       = t;
    while (*(volatile u16 *) REG_SQRTCNT & SQRTCNT_BUSY) {
    }
    if (func_0205d060(data_021027f8, 0x200, 4)) {
        l.s1.v      = self->step;
        l.n1.v      = self->ang.v - l.s1.v;
        l.n1c       = l.n1;
        self->ang.v = l.n1c.v;
    } else if (func_0205d060(data_021027f8, 0x100, 4)) {
        l.s2.v      = self->step;
        l.n2.v      = self->ang.v + l.s2.v;
        l.n2c       = l.n2;
        self->ang.v = l.n2c.v;
    }
    if (self->dist < self->dist_min) {
        self->dist = self->dist_min;
    }
    if (self->dist > self->dist_max) {
        self->dist = self->dist_max;
    }
    np.x    = tp.x + fx_mul(fx_cos(self->ang), self->dist);
    np.z    = tp.z + fx_mul(fx_sin(self->ang), self->dist);
    np.y    = self->dy_pos + tp.y;
    changed = vec_ne(&self->pos, &np);
    if (changed) {
        vec_set(&self->pos, &np);
        self->f49 = 1;
    }
    q.x = p->x;
    q.y = p->y;
    q.z = p->z;
    q.y = q.y + self->dy_out;
    func_020a019c(self, &q);
}
