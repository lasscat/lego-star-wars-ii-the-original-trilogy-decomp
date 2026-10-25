#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad1[0x40 - 0x34];
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 pad2[2];
    u8 f48;
    u8 f49;
    u8 pad3[0x1e4 - 0x4a];
    Vec3 target;
    u8 pad4[0x31c - 0x1f0];
    u16 f31c;
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

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u16 v;
} Half;

/* Single-field wrappers kept in one stack aggregate so that the per-angle copies and
 * argument copies stay in the frame as in the original. */
typedef struct {
    Half h5;
    Half b2;
    Half a2;
    Half b1;
    Half a1;
    Half pad;
    Fx qx;
    Fx qz;
    Fx qy;
} Loc;

void func_020a9308(Obj *obj, Vec3 *v1, void *v2, Vec3 *o1, Vec3 *o2);
s16 func_020985d8(s32 a, s32 b);

static inline u16 atan2_idx(s32 y, s32 x) {
    return func_020985d8(y, x);
}

void func_020a019c(Obj *obj, void *arg1) {
    Vec3 np;
    Vec3 v;
    Vec3 diff;
    Loc l;
    s64 t;
    s32 mag;
    s32 vx, vy, vz;

    np.x = 0;
    np.y = 0;
    np.z = 0;
    v.x  = 0;
    v.y  = 0;
    v.z  = 0;
    func_020a9308(obj, &obj->pos, arg1, &np, &obj->target);
    if (vec_ne(&obj->pos, &np)) {
        vec_set(&obj->pos, &np);
        obj->f49 = 1;
    }
    vz     = np.z - obj->target.z;
    vy     = np.y - obj->target.y;
    vx     = np.x - obj->target.x;
    diff.x = vx;
    diff.y = vy;
    diff.z = vz;
    if (&v != &diff) { // FAKE: always-true pointer test (inlined vector copy)
        v.z = vz;
        v.y = vy;
        v.x = vx;
    }
    t = (s64) v.x * v.x;
    t += (s64) v.z * v.z;
    t <<= 2;
    *(volatile u16 *) 0x040002B0 = 1;
    *(u64 *) 0x040002B8          = t;
    while (*(volatile u16 *) 0x040002B0 & 0x8000) {
    }
    mag    = ((s32) * (volatile u32 *) 0x040002B4 + 1) >> 1;
    l.qy.v = v.y; // FAKE: dead stack copy of the atan argument
    l.a1.v = -atan2_idx(v.y, mag);
    l.a2   = l.a1; // FAKE: dead stack copy of the angle
    if (obj->rot_x != l.a1.v) {
        obj->rot_x = l.a1.v;
        obj->f48   = 1;
    }
    l.qz.v = v.z; // FAKE: dead stack copy of the atan argument
    l.qx.v = v.x; // FAKE: dead stack copy of the atan argument
    l.b1.v = atan2_idx(v.x, v.z);
    l.b2   = l.b1; // FAKE: dead stack copy of the angle
    if (obj->rot_y != l.b1.v) {
        obj->rot_y = l.b1.v;
        obj->f48   = 1;
    }
    l.h5.v = obj->f31c;
    if (obj->rot_z != l.h5.v) {
        obj->rot_z = l.h5.v;
        obj->f48   = 1;
    }
}
