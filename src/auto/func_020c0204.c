/* Reconstructed from USA ARM9 at 0x020c0204 (560 bytes).
 *
 * Entry data_0210ecf4[t->slot] holds a u16 angle, a distance and a speed.
 * The s16 pair at index (angle >> 4) * 2 of data_020f88c4 is read as (sin, cos).
 * v starts as data_020ff9b4; self->mode picks which two of its components get
 * cos * dist and sin * dist (0: y,z  1: x,z  2: x,y).
 * Then angle += turn * scale and dist += speed * scale (fx32 multiplies, rounded),
 * and the new position is pos + v * scale. When it differs from t->pos it is
 * copied there and the byte at +0x45 is set to 1.
 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u16 v;
} Ang;

typedef struct {
    u16 angle;
    u8 pad2[6];
    s32 dist;
    s32 speed;
} Slot;

typedef struct {
    u8 pad0[0x24];
    u16 turn;
    u8 pad26[2];
    s32 mode;
} Mover;

typedef struct {
    u8 pad0[0x24];
    Vec3 pos;
    u8 pad30[0x15];
    u8 dirty;
    u8 pad46[6];
    s32 slot;
} Target;

extern Slot data_0210ecf4[];
extern Vec3 data_020ff9b4;
extern const s16 data_020f88c4[];

static inline s16 SinIdx(int idx) {
    return data_020f88c4[(idx >> 4) << 1];
}

static inline s16 CosIdx(int idx) {
    return data_020f88c4[((idx >> 4) << 1) + 1];
}

enum {
    FX32_SHIFT = 0xc,
    FX32_HALF  = 0x800
};

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + FX32_HALF) >> FX32_SHIFT);
}

static inline Ang angAdd(s32 base, Ang d) {
    Ang r;
    r.v = base + d.v;
    return r;
}

static inline u16 angAddTo(s32 base, Ang d) {
    return angAdd(base, d).v;
}

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x == b->x && a->y == b->y && a->z == b->z) {
        return 0;
    }
    return 1;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

void func_020c0204(Mover *self, Target *t, Fx scale) {
    Slot *slot;
    s32 angle;
    s32 cs;
    s32 sn;
    Vec3 v;
    u32 turn;
    u32 dx;
    u32 dy;
    u32 dz;
    s32 nx;
    s32 ny;
    s32 nz;
    Vec3 np;

    slot  = &data_0210ecf4[t->slot];
    angle = slot->angle;
    v.x   = data_020ff9b4.x;
    v.y   = data_020ff9b4.y;
    v.z   = data_020ff9b4.z;
    cs    = CosIdx(angle);
    sn    = SinIdx(angle);

    switch (self->mode) {
        case 0:
            v.y = FxMul(cs, slot->dist);
            v.z = FxMul(sn, slot->dist);
            break;
        case 1:
            v.x = FxMul(cs, slot->dist);
            v.z = FxMul(sn, slot->dist);
            break;
        case 2:
            v.x = FxMul(cs, slot->dist);
            v.y = FxMul(sn, slot->dist);
            break;
    }
    turn        = self->turn;
    turn        = FxMul(turn, scale.v);
    slot->angle = angAddTo(angle, (Ang) {turn});
    slot->dist += FxMul(slot->speed, scale.v);
    dz   = v.z;
    dz   = FxMul(dz, scale.v);
    dy   = v.y;
    dy   = FxMul(dy, scale.v);
    dx   = v.x;
    dx   = FxMul(dx, scale.v);
    nz   = t->pos.z + dz;
    ny   = t->pos.y + dy;
    nx   = t->pos.x + dx;
    np.x = nx;
    np.y = ny;
    np.z = nz;
    if (vec_ne(&t->pos, &np)) {
        vec_set(&t->pos, &np);
        t->dirty = 1;
    }
}
