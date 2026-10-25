#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad1[0x49 - 0x34];
    u8 f49;
    u8 pad2[0x242 - 0x4a];
    u8 f242;
    u8 pad3;
    s32 f244;
    s32 f248;
    s32 f24c;
} Obj;

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

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

void func_020aa794(Obj *obj, Vec3 *out);
void func_020a9634(Obj *obj, Vec3 *pos);

void func_020a2440(Obj *obj) {
    Vec3 np;
    Vec3 off;

    if (obj->f242 == 0) {
        return;
    }
    vec_copy(&np, &obj->pos);
    off.x = 0;
    off.y = 0;
    off.z = 0;
    func_020aa794(obj, &off);
    np.y = off.y + obj->f24c;
    if (np.y > obj->f248) {
        np.y = obj->f248;
    }
    if (np.y < obj->f244) {
        np.y = obj->f244;
    }
    if (vec_ne(&obj->pos, &np)) {
        vec_set(&obj->pos, &np);
        obj->f49 = 1;
    }
    func_020a9634(obj, &obj->pos);
}
