#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

struct Obj;
typedef struct Parent {
    u8 pad0[4];
    Vec3 pos;
} Parent;

typedef struct Obj {
    u8 pad0[0x20];
    Parent *parent;
    u8 pad1[0x78 - 0x24];
    Vec3 vel;
    u8 pad2[0xB0 - 0x84];
    Vec3 pos;
    u8 pad3[0xD1 - 0xBC];
    u8 posDirty;
} Obj;

extern u32 data_021094ac;
void func_02055128(void *, void *);

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

static inline int vec_nz(const Vec3 *v) {
    s32 xy;
    s32 moving;

    moving = 1;
    xy     = 1;

    if (v->x == 0 && v->y == 0) {
        xy = 0;
    }
    if (xy == 0 && v->z == 0) {
        moving = 0;
    }
    return moving;
}

static inline void vec_add(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    s32 z = a->z + b->z;
    s32 y = a->y + b->y;
    s32 x = a->x + b->x;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

enum {
    POS_DIRTY = 1,
};

/* Applies the object's per-frame velocity to its position (marking the position dirty when it
 * changes) and shifts the parent's position by the same delta, then notifies the global manager. */
void func_02017d24(Obj *obj) {
    Vec3 np;
    Parent *parent;

    if (!vec_nz(&obj->vel)) {
        return;
    }
    vec_add(&np, &obj->pos, &obj->vel);
    if (vec_ne(&obj->pos, &np)) {
        vec_set(&obj->pos, &np);
        obj->posDirty = POS_DIRTY;
    }
    parent = obj->parent;
    if (parent == NULL) {
        return;
    }
    parent->pos.x += obj->vel.x;
    parent->pos.y += obj->vel.y;
    parent->pos.z += obj->vel.z;
    func_02055128(&data_021094ac, obj);
}
