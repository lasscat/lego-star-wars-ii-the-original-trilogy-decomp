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
    u8 pad2[0x1a0 - 0x4a];
    s32 f1a0;
    s32 f1a4;
    u8 pad3[0x1ac - 0x1a8];
    u32 f1ac;
    u8 f1b0;
    u8 pad4[0x1c4 - 0x1b1];
    s32 f1c4;
    s32 f1c8;
} Obj;

typedef struct {
    u8 pad0[0x40];
    u8 f40;
    u8 pad1[0xb0 - 0x41];
    Vec3 fb0;
    u8 pad2[0xca - 0xbc];
    Half fca;
    u8 pad3[0xd0 - 0xcc];
    u8 fd0;
    u8 fd1;
    u8 pad4[0x6b4 - 0xd2];
    Half f6b4;
} Ent;

typedef struct {
    u8 pad[0x2a];
    u8 f2a;
} Cfg;

typedef struct {
    u8 pad[4];
    void *f4;
} Mgr;

typedef struct {
    u8 pad[0x28];
    u8 f28;
} Self;

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

/* Store v into *d and return a copy. The target keeps both the store to the
 * caller's local and the by-value parameter copy made from it.
 */
static inline UnkVal fx_init(UnkVal *d, s32 v) {
    d->v = v;
    return *d;
}

static inline void obj_setup(UnkVal f1c4, UnkVal f1c8, UnkVal f1a0, UnkVal f1a4) {
    Obj *o  = func_020aaeb4();
    o->f1c4 = f1c4.v;
    o->f1c8 = f1c8.v;
    o->f1a0 = f1a0.v;
    o->f1a4 = f1a4.v;
    o->f1b0 = 1;
    o->f1ac |= 4;
}

static inline void ent_set_ca(Ent *e, Half h) {
    if (!half_eq(e->fca.v, h)) {
        e->fca = h;
        e->fd0 = 1;
    }
}

void func_020a0440(Obj *, UnkVal, u8);
s32 func_0207fcc0(void);
void func_02081994(void *, s32);
void func_02090c1c(void *);
void *func_020917c8(void *, s32, s32);
void func_02093690(void *, void *);
void func_020b9c90(void *);

extern Cfg data_021027f8;
extern Mgr data_02102900;
extern M2C_UNK data_0210930c;
extern Ent *data_02109358[];
extern M2C_UNK data_0210db30;

static inline void ent_set_pos(Ent *e, const Vec3 *p) {
    if (vec_ne(&e->fb0, p)) {
        vec_set(&e->fb0, p);
        e->fd1 = 1;
    }
}

static inline void half_copy(Half *d, const Half *s) {
    half_set(d, *s);
}

static inline void ent_get_h(Ent *e, Half *d) {
    half_copy(d, &e->f6b4);
}

static inline void ent_set_ca_cur(const Half *h) {
    ent_set_ca(data_02109358[data_021027f8.f2a], *h);
}

static inline void ent_restore_h(const Half *h) {
    ent_set_ca_cur(h);
    half_copy(&data_02109358[data_021027f8.f2a]->f6b4, h);
}

static inline Half half_make(u16 v) {
    Half h;
    h.v = v;
    return h;
}

static inline void obj_set_rot(Half x, Half y, Half z) {
    Rot3 r;
    Rot3 *pr;
    Obj *o;

    o  = func_020aaeb4();
    pr = &r;
    /* Member copies keep the three dead Half argument stores of the target. */
    pr->x.v = x.v;
    pr->y.v = y.v;
    pr->z.v = z.v;
    if (!rot_eq(pr, &o->rot)) {
        rot_set(&o->rot, pr);
        o->f48 = 1;
    }
}

/* Integers scaled by 1 << 12; the readers of these fields were not traced. */
enum {
    SCALED_1    = 0x1000,
    SCALED_192  = 0xc0000,
    SCALED_256  = 0x100000,
    SCALED_1000 = 0x3e8000
};

/* Entry 3 of the handler table data_020ff340. Resets the shared object
 * returned by func_020aaeb4 (&data_02109c88): f1c4/f1c8 = 256/192 (the DS
 * screen size in pixels) and f1a0/f1a4 = 1/1000, all scaled by 1 << 12, then
 * f1b0 = 1 and bit 2 of f1ac. Its position (+0x28) and its three u16 values at
 * +0x40 are zeroed; the f49/f48 change flags are raised only when a value
 * differed. SCALED_1 and the current slot data_021027f8.f2a then go to
 * func_020a0440, followed by func_02090c1c(&data_0210930c) and
 * func_020b9c90(&data_0210db30).
 *
 * When arg0->f28 is set, the fb0 vector, f6b4 value and f40 byte of the slot's
 * entity (data_02109358[slot]) are saved. The id from func_0207fcc0 goes to
 * func_02081994, and id + 0x49 goes to func_020917c8 for the slot. The entity
 * now in the slot gets the vector back in fb0 (fd1 raised if it differed) and
 * the value in fca (fd0 raised if it differed) and f6b4. func_02093690 runs for
 * that entity if the saved f40 byte was set; f28 is cleared last.
 */
void func_0207fdec(Self *arg0) {
    Vec3 saved_pos;
    Vec3 v;
    UnkVal v1c4;
    UnkVal v1c8;
    UnkVal v1a0;
    UnkVal v1a4;
    UnkVal s;
    Half saved_h;
    Vec3 *pv;
    Obj *o;
    u8 flag;
    s32 id;
    Ent *e;
    Vec3 *src;

    obj_setup(fx_init(&v1c4, SCALED_256), fx_init(&v1c8, SCALED_192), fx_init(&v1a0, SCALED_1), fx_init(&v1a4, SCALED_1000));

    v.x = 0;
    v.y = 0;
    v.z = 0;
    pv  = &v;
    o   = func_020aaeb4();
    if (vec_ne(&o->pos, pv)) {
        vec_set(&o->pos, pv);
        o->f49 = 1;
    }
    obj_set_rot(half_make(0), half_make(0), half_make(0));

    s.v = SCALED_1;
    func_020a0440(func_020aaeb4(), s, data_021027f8.f2a);
    func_02090c1c(&data_0210930c);
    func_020b9c90(&data_0210db30);
    if (arg0->f28 == 0) {
        return;
    }

    saved_pos.x = 0;
    saved_pos.y = 0;
    saved_pos.z = 0;
    e           = data_02109358[data_021027f8.f2a];
    src         = &e->fb0;
    vec_set(&saved_pos, src);
    ent_get_h(e, &saved_h);
    flag = e->f40;
    id   = func_0207fcc0();
    func_02081994(data_02102900.f4, id);
    func_020917c8(&data_0210930c, data_021027f8.f2a, id + 0x49);
    ent_set_pos(data_02109358[data_021027f8.f2a], &saved_pos);
    ent_restore_h(&saved_h);
    if (flag) {
        func_02093690(&data_0210930c, data_02109358[data_021027f8.f2a]);
    }
    arg0->f28 = 0;
}
