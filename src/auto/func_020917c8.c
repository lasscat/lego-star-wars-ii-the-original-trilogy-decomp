#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0xb0];
    Vec3 pos;
    u8 padbc[0x6a0 - 0xbc];
    Vec3 f_6a0;
    u8 pad6ac[0x7fc - 0x6ac];
    s32 f_7fc;
    u8 pad800[4];
    s32 f_804;
} Ent;

typedef struct {
    u8 pad0[0x4c];
    Ent *slots[4];
} Globals;

typedef struct {
    u8 pad0[0x29];
    u8 count;
    u8 active;
} PadState;

extern Globals data_0210930c;
extern PadState data_021027f8;

s32 func_02091904(Globals *, s32, s32);
void func_020b8f70(s32, s32);
Ent *func_02091b88(Globals *, s32, s32, Vec3 *, s32);
void *func_020aaeb4(void);
void func_020a0370(void *, Ent *);
void func_02091a78(Globals *, Vec3 *);

static inline void vec_copy(Vec3 *d, const Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

Ent *func_020917c8(Globals *arg0, s32 arg1, s32 arg2) {
    Vec3 sp10;
    Vec3 sp4;
    Ent *r4;
    s32 v804;
    Ent *e;
    u32 i;

    if (func_02091904(arg0, arg1, arg2) == 0) {
        func_020b8f70(0xb7, 0);
        return arg0->slots[arg1];
    }

    vec_copy(&sp10, &arg0->slots[arg1]->pos);
    e = arg0->slots[arg1];
    vec_copy(&sp4, &e->f_6a0);
    v804 = e->f_804;

    r4 = func_02091b88(&data_0210930c, arg1, arg2, &sp10, 1);
    vec_set(&r4->f_6a0, &sp4);

    if (arg1 == data_021027f8.active) {
        func_020a0370(func_020aaeb4(), r4);
    }

    r4->f_804 = v804;

    for (i = 0; i < data_021027f8.count; i++) {
        if (arg0->slots[i] != NULL) {
            arg0->slots[i]->f_7fc = 0;
        }
    }

    func_02091a78(arg0, &r4->pos);
    return r4;
}
