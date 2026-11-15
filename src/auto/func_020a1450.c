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
    u8 pad2[0x324 - 0x4a];
    s32 f324;
} Obj;

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

extern u8 data_0210930c[];
void func_020aa794(Obj *obj, Vec3 *out);
void func_02092eb0(void *data, Vec3 *a, Vec3 *b);
void func_020a019c(Obj *obj, Vec3 *pos);

/* Runs func_02092eb0 on data_0210930c twice: first with (0, 0xC000, 0), then with
 * pos - off where y is zero. Puts the y difference back afterwards. If the result
 * differs from obj->pos, copies it there and sets f49. Last, passes the point
 * with f324 added to y to func_020a019c. */
void func_020a1450(Obj *obj) {
    Vec3 off;
    Vec3 v;
    Vec3 np;
    Vec3 d;
    s32 z, x, y;
    s32 dy;
    s32 vy;
    s32 py;

    off.x = 0;
    off.y = 0;
    off.z = 0;
    func_020aa794(obj, &off);
    v.x = 0;
    v.y = 0xC000;
    v.z = 0;
    func_02092eb0(data_0210930c, &off, &v);
    py = obj->pos.y;
    z  = obj->pos.z - off.z;
    y  = off.y;
    x  = obj->pos.x - off.x;
    y -= off.y;
    d.y = y;
    d.x = x;
    d.z = z;
    dy  = py - off.y;
    vec_set(&v, &d);
    vy  = v.y;
    v.y = 0;
    func_02092eb0(data_0210930c, &off, &v);
    off.y += vy;
    off.y += dy;
    if (vec_ne(&obj->pos, &off)) {
        vec_set(&obj->pos, &off);
        obj->f49 = 1;
    }
    func_020aa794(obj, &off);
    np.x = off.x;
    np.y = off.y;
    np.z = off.z;
    np.y = np.y + obj->f324;
    func_020a019c(obj, &np);
}
