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
    s32 v;
} Word;

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad1[0x49 - 0x34];
    u8 f49;
} Obj;

typedef struct {
    u8 pad0[8];
    u32 f8;
    u8 pad1[0xb0 - 0xc];
    Vec3 pos;           /* +0xb0, dirty byte +0xd1 (as in func_0205639c) */
    u8 pad2[0xca - 0xbc];
    Half angle;         /* +0xca, binary angle, dirty byte +0xd0 */
    u8 pad3[0xd0 - 0xcc];
    u8 angle_dirty;
    u8 pos_dirty;
    u8 pad4[0x180 - 0xd2];
    u16 f180;
} Sub;

typedef struct {
    u8 pad[0x28];
    Sub *sub;
} Main;

typedef struct {
    u8 pad[0x2a];
    u8 f2a;
} Cfg;

typedef struct {
    u8 pad[0x68];
    void *f68;
} Tab;

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

/* Writing the whole Half through a u16 store keeps the (never read) stack temporaries in the
 * frame; h->v = v lets mwcc drop them. */
static inline void half_set(Half *h, u16 v) {
    *(u16 *) h = v;
}

static inline void sub_set_angle(Sub *sub, u16 angle) {
    if (sub->angle.v != angle) {
        sub->angle.v     = angle;
        sub->angle_dirty = 1;
    }
}

enum {
    CLEAR_DEPTH_MAX  = 0x7fff, /* G3X_SetClearColor depth (15 bit) */
    CLEAR_POLYGON_ID = 0x3f,
    ANGLE_HALF_TURN  = 0x8000, /* binary angle: 0x10000 = 360 degrees */
};

extern u8 data_02101b78[];
extern Cfg data_021027f8;
extern Tab data_0210930c;

void G3X_SetClearColor(s32, s32, s16, s32, s32);
void func_02053f60(void *, s32);
void func_02001688(s32);
void func_02055c48(s32);
void func_0200fae8(void);
void func_02076c50(void *, s32);
void func_020016c0(void);
void func_020909e8(void *, s32, s32);
Obj *func_020aaeb4(void);
void func_020a99bc(void *, u8);
void func_020a019c(void *, void *);
void func_020a0440(void *, UnkVal, u8);
void func_020768fc(void *, s32);
void func_02076a7c(void *);

/* Sets a black clear colour (alpha 0, maximum depth, polygon ID 63), calls
 * func_02001688/func_02055c48/func_0200fae8/func_02076c50, clears bit 0x40000 and sets bit 1 of
 * arg0->sub->f8, moves the func_020aaeb4 object to (0, 0, -0x1000) (dirty byte +0x49), passes
 * (0, 0, 0x1e000) to func_020a019c, then sets arg0->sub's position to (0, 0, 0x55000) and its
 * angle to a half turn, each with its dirty byte, before func_020768fc and func_02076a7c.
 * The Word and Half locals stand for stack slots the target writes but never reads back. */
void func_0207617c(Main *arg0) {
    Vec3 new_pos;
    Vec3 v2;
    Vec3 sub_pos;
    UnkVal s;
    Word qz;
    Word qy;
    Word qx;
    Word pz;
    Word py;
    Word px;
    Half hq;
    Half hp;
    Vec3 *pv;
    Obj *obj;
    Sub *sub;

    G3X_SetClearColor(0, 0, CLEAR_DEPTH_MAX, CLEAR_POLYGON_ID, 0);
    func_02053f60(data_02101b78, 0x1000);
    func_02001688(0);
    func_02055c48(0);
    func_0200fae8();
    func_02076c50(arg0, 0);
    func_020016c0();
    arg0->sub->f8 &= ~0x40000;
    arg0->sub->f8 |= 1;
    func_020909e8(data_0210930c.f68, 0, 0);
    func_020a99bc(func_020aaeb4(), 0);

    new_pos.x = 0;
    new_pos.y = 0;
    new_pos.z = -0x1000;
    pv        = &new_pos;
    obj       = func_020aaeb4();
    if (vec_ne(&obj->pos, pv)) {
        vec_set(&obj->pos, pv);
        obj->f49 = 1;
    }

    v2.x = 0;
    v2.y = 0;
    v2.z = 0x1e000;
    func_020a019c(func_020aaeb4(), &v2);

    s.v = 0x1000;
    func_020a0440(func_020aaeb4(), s, data_021027f8.f2a);

    sub       = arg0->sub;
    qy.v      = 0;
    py        = qy;
    qz.v      = 0;
    pz        = qz;
    qx.v      = 0x55000;
    px        = qx;
    sub_pos.x = pz.v;
    sub_pos.y = py.v;
    sub_pos.z = px.v;
    pv        = &sub_pos;
    if (vec_ne(&sub->pos, pv)) {
        vec_set(&sub->pos, pv);
        sub->pos_dirty = 1;
    }

    half_set(&hq, ANGLE_HALF_TURN);
    half_set(&hp, ANGLE_HALF_TURN);
    sub_set_angle(arg0->sub, ANGLE_HALF_TURN);

    func_020768fc(arg0, arg0->sub->f180 - 0x22f);
    func_02076a7c(arg0);
}
