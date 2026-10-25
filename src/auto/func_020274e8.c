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
} VecFx;

typedef struct {
    u16 v;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
} Key;

typedef struct {
    u8 pad0[0xb0];
    VecFx pos;
    u8 padbc[0xca - 0xbc];
    Angle yaw;
} Entity;

typedef struct {
    Angle a;
    Angle b;
    Angle c;
} Loc;

extern void func_0202732c(void *);
extern s16 func_020985d8(s32, s32);

static inline void vec_set(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline u16 fx_atan2(Fx x, Fx z) {
    return func_020985d8(x.v, z.v);
}

void func_020274e8(Key *out, Entity *ent, VecFx *pos) {
    s32 s;
    Fx qz;
    Fx qx;
    VecFx d;
    Loc l;
    u16 yaw;

    func_0202732c(out);
    vec_set((s32 *) &d, pos->x.v - ent->pos.x.v, pos->y.v - ent->pos.y.v, pos->z.v - ent->pos.z.v);
    qz     = d.z;
    qx     = d.x;
    yaw    = fx_atan2(qx, qz);
    l.b    = ent->yaw;
    l.c.v  = yaw - l.b.v;
    l.a    = l.c;
    out->v = l.a.v;
    s      = *(s16 *) &l.c;
    if (s < 0) {
        s = -s;
    }
    if (s > 0x5555) {
        out->f2 = 0;
    } else {
        out->f2 = 1;
    }
    out->f4 = 100;
    out->f5 = 100;
}
