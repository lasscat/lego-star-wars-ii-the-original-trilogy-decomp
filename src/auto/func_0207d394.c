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
    Half x;
    Half y;
    Half z;
} Rot3;

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad1[0x40 - 0x34];
    Rot3 rot;
    u8 f46[2];
    u8 f48;
    u8 f49;
    u8 pad2[0x1ac - 0x4a];
    u32 f1ac;
    u8 f1b0;
} Obj;

typedef struct {
    u8 pad[0x2a];
    u8 f2a;
} Cfg;

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

static inline void rot_swz(Rot3 *d, const Rot3 *s) {
    d->x = s->z;
    d->y = s->y;
    d->z = s->x;
}

static inline int half_eq(u16 a, Half b) {
    return a == b.v;
}

static inline int rot_eq(const Rot3 *a, const Rot3 *b) {
    return half_eq(a->x.v, b->x) && half_eq(a->y.v, b->y) && half_eq(a->z.v, b->z);
}

static inline void half_set(Half *d, Half s) {
    d->v = s.v;
}

static inline void rot_set(Rot3 *d, const Rot3 *s) {
    half_set(&d->x, s->x);
    half_set(&d->y, s->y);
    half_set(&d->z, s->z);
}

Obj *func_020aaeb4(void);
void func_020a0440(Obj *, UnkVal, u8);
void func_0207d684(void *);

extern s32 data_027e02a4;
extern Cfg data_021027f8;

void func_0207d394(u8 *arg0) {
    Vec3 v;
    Vec3 *pv;
    UnkVal s;
    Rot3 r;
    Rot3 q;
    Rot3 p;
    Rot3 *pr;
    Obj *o;

    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    o       = func_020aaeb4();
    o->f1b0 = 0;
    o->f1ac |= 4;
    v.x = 0;
    v.y = 0x9000;
    v.z = 0x1e000;
    pv  = &v;
    o   = func_020aaeb4();
    if (vec_ne(&o->pos, pv)) {
        vec_set(&o->pos, pv);
        o->f49 = 1;
    }
    q.x.v = 0;
    q.y.v = 0;
    q.z.v = 0xfdde;
    p     = q;
    o     = func_020aaeb4();
    pr    = &r;
    rot_swz(pr, &p);
    if (!rot_eq(pr, &o->rot)) {
        rot_set(&o->rot, pr);
        o->f48 = 1;
    }

    s.v = 0x1000;
    func_020a0440(func_020aaeb4(), s, data_021027f8.f2a);
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    func_0207d684(arg0 + 0x28);
}
