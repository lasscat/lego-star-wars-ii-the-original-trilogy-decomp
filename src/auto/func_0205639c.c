#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad0[0xB0];
    Vec3 pos;
    u8 pad1[0xCA - 0xBC];
    u16 angle;
    u8 pad2[0xD0 - 0xCC];
    u8 angleDirty;
    u8 posDirty;
} Obj;

typedef struct {
    u16 v;
} Ang;

typedef struct {
    u8 pad[0x68];
    void *f68;
} Global;

extern Global data_0210930c;

void *func_02067080(M2C_UNK, u8, u8);
s32 func_020906ec(void *, s32);
s32 func_02062a7c(s32, s32);
void func_020906a8(Vec3 *, void *, s32, s32);
void func_02098440(u16 *, u8);

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

void func_0205639c(M2C_UNK arg0, u8 *arg1) {
    Vec3 pos;
    Ang a;
    Ang b;
    Obj *obj;
    s32 idx;
    s32 t;

    obj = func_02067080(arg0, arg1[0], arg1[1]);
    if (obj == NULL) {
        return;
    }
    idx = arg1[2];
    t   = func_020906ec(data_0210930c.f68, idx);
    t   = func_02062a7c(0, t);
    func_020906a8(&pos, data_0210930c.f68, idx, t);
    if (vec_ne(&obj->pos, &pos)) {
        vec_set(&obj->pos, &pos);
        obj->posDirty = 1;
    }
    func_02098440(&a.v, arg1[3]);
    b = a; // FAKE: dead stack copy of the angle; reproduces the strh [sp] before the compare
    if (obj->angle != b.v) {
        obj->angle      = b.v;
        obj->angleDirty = 1;
    }
}
