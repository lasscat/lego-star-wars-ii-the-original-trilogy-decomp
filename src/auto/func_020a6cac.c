#include "m2c.h"

typedef struct {
    s16 x, y, z;
} Pt16;

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    s32 v;
} Fx;

Pt16 *func_02067b48(void *, s32);
u8 func_02067b54(void *);
s32 func_020a6e98(void *, s32, s32);
u8 func_020a6efc(void *, s32, s32);
u8 func_020a6f3c(void *, s32, s32);
void func_020a6f80(void *, void *, Fx, Vec3 *, Vec3 *, Vec3 *, Vec3 *, s32, s32, s32, s32);
void func_020a827c(void *, void *, Fx, Vec3 *, Vec3 *, Vec3 *, s32, s32, s32);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

void func_020a6cac(u8 *self, void *r1, Fx t, Vec3 a, Vec3 b, void *list) {
    u32 lo = self[0x295];
    u32 hi = self[0x296];
    u32 ia, ib;
    s32 x, y, z;
    Pt16 *p;
    Vec3 tmp;
    Vec3 pa;
    Vec3 pb;

    if (lo > hi) {
        u32 s = lo;
        lo    = hi;
        hi    = s;
        tmp.x = a.x;
        tmp.y = a.y;
        tmp.z = a.z;
        vec_set(&a, &b);
        vec_set(&b, &tmp);
        t.v = 0x1000 - t.v;
    }
    ia = func_020a6efc(self, lo, hi);
    ib = func_020a6f3c(self, lo, hi);
    if (ia >= func_02067b54(list)) {
        return;
    }
    p    = func_02067b48(list, ia);
    z    = p->z << 12;
    y    = p->y << 12;
    x    = p->x << 12;
    pa.x = x;
    pa.y = y;
    pa.z = z;
    if (func_020a6e98(self, lo, hi) != 0) {
        p    = func_02067b48(list, ib);
        z    = p->z << 12;
        y    = p->y << 12;
        x    = p->x << 12;
        pb.x = x;
        pb.y = y;
        pb.z = z;
        func_020a6f80(self, r1, t, &a, &b, &pa, &pb, lo, hi, ia, ib);
    } else {
        func_020a827c(self, r1, t, &a, &b, &pa, lo, hi, ia);
    }
}
