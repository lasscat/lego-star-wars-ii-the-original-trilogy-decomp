#include "m2c.h"

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u16 v;
} Angle;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} V3;

extern s16 func_020985d8(s32, s32);

static inline void vec_copy(V3 *d, const V3 *s) {
    if (d != s) {
        d->x.v = s->x.v;
        d->y.v = s->y.v;
        d->z.v = s->z.v;
    }
}

static inline Angle fx_atan2(Fx x, Fx z) {
    Angle r;
    r.v = func_020985d8(x.v, z.v);
    return r;
}

static inline void set_yaw(void *a, Angle yaw) {
    if (M2C_FIELD(a, u16 *, 0xca) != yaw.v) {
        M2C_FIELD(a, u16 *, 0xca) = yaw.v;
        M2C_FIELD(a, u8 *, 0xd0)  = 1;
    }
}

void func_0201812c(void *a, V3 *b, s32 flag) {
    V3 d;
    V3 t;
    Fx qz;
    Fx qx;
    s32 v0;
    s32 v1;
    s32 v2;

    v2    = b->z.v - M2C_FIELD(a, s32 *, 0xb8);
    v1    = b->y.v - M2C_FIELD(a, s32 *, 0xb4);
    v0    = b->x.v - M2C_FIELD(a, s32 *, 0xb0);
    d.x.v = v0;
    d.y.v = v1;
    d.z.v = v2;
    if (flag) {
        v2    = M2C_FIELD(a, s32 *, 0xb8) - b->z.v;
        v1    = M2C_FIELD(a, s32 *, 0xb4) - b->y.v;
        v0    = M2C_FIELD(a, s32 *, 0xb0) - b->x.v;
        t.x.v = v0;
        t.y.v = v1;
        t.z.v = v2;
        vec_copy(&d, &t);
    }
    if (d.x.v == 0 && d.z.v == 0) {
        return;
    }
    qz = d.z;
    qx = d.x;
    set_yaw(a, fx_atan2(qx, qz));
}
