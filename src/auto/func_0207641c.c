/* func_0207641c: takes a context that holds a target object (+0x28), a target position (+0x30, three
 * s32) and target angles (+0x3c, three u16). The object's position (+0xb0) and angles (+0xc8) are
 * overwritten only when they differ, setting the matching dirty flag (+0xd1 position, +0xd0 angles).
 * Then the 3D clear attributes (rgb 0, alpha 0x1f, depth 0x7fff, polygon id 0x3f, no fog) and engine state are set up through
 * a fixed sequence of calls, and bit 15 of the hardware register at 0x04000304 (POWCNT1 display swap bit) is set.
 */
#include "m2c.h"

enum {
    CLEAR_ALPHA   = 0x1f,
    CLEAR_DEPTH   = 0x7fff,
    CLEAR_POLY_ID = 0x3f,
    BUFFER_SIZE   = 0x1000,
    ARG_13        = 0x13,
    POWCNT1_ADDR  = 0x04000304,
    POWCNT1_SWAP  = 0x8000,
};

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
} Ang3;

typedef struct {
    u8 pad0[0xB0];
    Vec3 pos;
    u8 pad1[0xC8 - 0xBC];
    Ang3 ang;
    u8 pad2[0xD0 - 0xCE];
    u8 angDirty;
    u8 posDirty;
} Obj;

typedef struct {
    u8 pad0[0x28];
    Obj *obj;
    u8 pad1[4];
    Vec3 pos;
    Ang3 ang;
} Ctx;

typedef struct {
    u8 pad[0x68];
    void *f68;
} Global;

extern u8 data_021027f8[];
extern Obj *data_02109358[];
extern Global data_0210930c;
extern u8 data_02101b78[];
extern u8 data_02102900[];

void func_020909e8(void *, s32, s32);
void func_02053f44(void *, s32);
void G3X_SetClearColor(s32, s32, s16, s32, s32);
void func_02001688(s32);
void func_0200faf8(void);
void func_02076c50(void *, s32);
void func_020016c0(void);
void *func_020aaeb4(void);
void func_020a99bc(void *, u8);
void func_020a3458(void *, s8);
void func_02060158(void *, s32, s32, s32);
void func_02063a90(s32, s32);

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

static inline int half_eq(const Half *a, Half b) {
    return a->v == b.v;
}

static inline void half_set(Half *d, Half v) {
    d->v = v.v;
}

static inline void sync_pos(Obj *o, Ctx *c) {
    if (vec_ne(&o->pos, &c->pos)) {
        vec_set(&o->pos, &c->pos);
        o->posDirty = 1;
    }
}

static inline void sync_ang(Obj *o, Ctx *a) {
    int e;
    int f;
    f = 0;
    e = 0;
    if (half_eq(&a->ang.x, o->ang.x)) {
        if (half_eq(&a->ang.y, o->ang.y)) {
            e = 1;
        }
    }
    if (e) {
        if (half_eq(&a->ang.z, o->ang.z)) {
            f = 1;
        }
    }
    if (!f) {
        half_set(&o->ang.x, a->ang.x);
        half_set(&o->ang.y, a->ang.y);
        half_set(&o->ang.z, a->ang.z);
        o->angDirty = 1;
    }
}

void func_0207641c(Ctx *c) {
    sync_pos(c->obj, c);
    sync_ang(c->obj, c);
    M2C_FIELD(data_02109358[data_021027f8[0x2a]], u8 *, 0x1ad) = 0;
    func_020909e8(data_0210930c.f68, 0, 1);
    func_02053f44(data_02101b78, BUFFER_SIZE);
    G3X_SetClearColor(0, CLEAR_ALPHA, CLEAR_DEPTH, CLEAR_POLY_ID, 0);
    func_02001688(0);
    func_0200faf8();
    func_02076c50(c, 1);
    func_020016c0();
    func_020a99bc(func_020aaeb4(), 1);
    func_020a3458(func_020aaeb4(), 1);
    func_02060158(data_02102900, 0, ARG_13, 0);
    func_02063a90(0, 0);
    *(u16 *) POWCNT1_ADDR |= POWCNT1_SWAP;
}
