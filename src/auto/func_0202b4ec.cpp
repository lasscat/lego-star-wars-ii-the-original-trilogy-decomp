#include "m2c.h"

typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

struct Fx {
    s32 v;
    Fx() {}
    operator s32() const {
        return v;
    }
};

typedef struct {
    s32 x, y, z;
} Vec3;

struct Rider {
    u8 pad0[0x26];
    u8 busy;
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void setAnim(s32 anim, s32 a, s32 b, s32 c); // Slot 0x24.
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual Fx getSpeed(s32 which); // Slot 0x3c.

    u8 pad4[0x4];
    u32 flags;
    u8 padc[0x20];
    Rider *rider;
    u8 pad30[0x10];
    u8 b40;
    u8 b41;
    u8 pad42[0x12];
    s32 f54;
    u8 pad58[0x58];
    Vec3 pos;
    u8 padbc[0x5e4];
    Vec3 f6a0;
};

struct Self {
    u8 pad0[0x64];
    Vec3 target;
    u8 pad70[0x23];
    u8 state;
};

struct Game {
    u8 pad0[0x4c];
    Entity *player;
};

extern "C" Game data_0210930c;
extern "C" Vec3 data_020ff9b4;

extern "C" Fx func_02007f24(f64 d);
extern "C" s32 func_0200aef8(Vec3 *a, Vec3 *b, Fx r);
extern "C" s32 func_0200f5d0(Vec3 *a, Vec3 *b, s32 r, Fx *out);
extern "C" void func_02017ee4(Entity *self, Vec3 *vec, s32 blend);
extern "C" void func_0201812c(Entity *a, Vec3 *b, s32 flag);
extern "C" u16 func_0204fa30(void *arg0);
extern "C" s8 func_02093534(Game *g, Entity *e);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline Fx fx_neg(const Fx *a) {
    Fx r;
    r.v = -a->v;
    return r;
}

static inline s32 fx_mulf(s32 a, Fx b) {
    Fx c = b;
    return fx_mul(a, c.v);
}

static inline s32 fx_sqv(Fx a) {
    Fx c = a;
    return fx_mul(a.v, c.v);
}

// FAKE: empty sink; its arguments are expanded z, y, x (stack copies of s at
// ascending addresses x, y, z) but evaluated x, y, z, as in the target.
static inline void vec_sink3(s32 z, s32 y, s32 x) {}

static inline void vec_scale(Vec3 *v, Fx s) {
    vec_sink3(v->z = fx_mulf(v->z, s), v->y = fx_mulf(v->y, s), v->x = fx_mulf(v->x, s));
}

static inline void vec_dir(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    s64 t;
    s32 sqrt;
    s64 div;

    s32 dz = a->z - b->z;
    s32 dy = a->y - b->y;
    s32 dx = a->x - b->x;

    d->x = dx;
    d->y = dy;
    d->z = dz;
    if (dx == 0 && dy == 0 && dz == 0) {
        vec_set(d, &data_020ff9b4);
        return;
    }
    t = (s64) d->x * d->x;
    t += (s64) d->y * d->y;
    t += (s64) d->z * d->z;

    (*(vu16 *) 0x04000280) = 2;
    (*(vu64 *) 0x04000290) = 1LL << 56;
    (*(vu64 *) 0x04000298) = t;

    (*(vu16 *) 0x040002B0) = 1;
    (*(u64 *) 0x040002B8)  = t << 2;

    while ((*(vu16 *) 0x040002B0) & 0x8000) {
    }
    sqrt = (s32) (*(vu32 *) 0x040002B4);

    while ((*(vu16 *) 0x04000280) & 0x8000) {
    }
    div = (s64) (*(u64 *) 0x040002A0);

    div *= sqrt;

    d->x = (s32) ((div * d->x + (1LL << 44)) >> 45);
    d->y = (s32) ((div * d->y + (1LL << 44)) >> 45);
    d->z = (s32) ((div * d->z + (1LL << 44)) >> 45);
}

static inline s32 is_locked(Entity *e) {
    s32 r = 0;
    if (e->b40 != 0 && e->b41 != 0) {
        s32 m = e->f54;
        if (m != 0) {
            m -= 4;
        }
        if (m != 0) {
            r = 1;
        }
    }
    return r;
}

static inline s32 is_riding(Entity *e) {
    return e->rider != 0 && e->rider->busy != 0;
}

enum {
    ENTITY_FLAG_200 = 0x200, // e->flags bit: set on the non-moving paths, cleared after a move
    BLEND_4B        = 0x4b,  // third argument of func_02017ee4
};

// Three-state follower update for e against the player position (data_0210930c +0x4c, pos at +0xb0).
// Range = 4.0 + 12.0 * level (level from func_02093534); near = func_0200f5d0 hit with dist < 2.0^2.
// State 0: setAnim(0, 1, 1), remember the player position, go to state 1.
// State 1: when near or out of range, move toward the player (away when near) at getSpeed(6), state 2.
// State 2: when in range again (or the target test fails while not near), back to state 1; else move.
extern "C" void func_0202b4ec(Self *self, Entity *e) {
    Vec3 dir1;
    Vec3 dir2;
    Vec3 *ppos = &data_0210930c.player->pos;
    Vec3 *pos  = &e->pos;
    Fx speed   = e->getSpeed(6);
    Fx range;
    Fx dist;
    Fx four;
    Fx twelve;
    s8 level;
    s32 hit;
    s32 near;
    s32 lim;

    level = func_02093534(&data_0210930c, e);
    if (e->b40 != 0 && !is_locked(e)) {
        if (func_0204fa30(&e->b40) != 5) {
            vec_set(&e->f6a0, pos);
        }
    }
    range.v = func_02007f24(4.0) + fx_mul(func_02007f24(12.0), level << 12);
    dist.v  = 0;
    hit     = func_0200f5d0(pos, ppos, range.v, &dist);
    lim     = fx_sqv(func_02007f24(2.0));
    near    = 0;
    if (hit != 0 && dist.v < lim) {
        near = 1;
    }

    switch (self->state) {
        case 0:
            e->setAnim(0, 1, 1, 0);
            vec_set(&self->target, ppos);
            self->state = 1;
            e->flags |= ENTITY_FLAG_200;
            return;
        case 1:
            if (near || hit == 0) {
                vec_set(&self->target, ppos);
                vec_dir(&dir1, ppos, &e->pos);
                if (near) {
                    vec_scale(&dir1, fx_neg(&speed));
                    func_0201812c(e, ppos, 1);
                } else {
                    vec_scale(&dir1, speed);
                    func_0201812c(e, ppos, 0);
                }
                e->setAnim(6, 1, 0, 0);
                if (!is_riding(e)) {
                    func_02017ee4(e, &dir1, BLEND_4B);
                }
                e->flags &= ~ENTITY_FLAG_200;
                self->state = 2;
                return;
            }
            e->setAnim(0, 1, 0, 0);
            e->flags |= ENTITY_FLAG_200;
            return;
        case 2:
            if (hit != 0 || (func_0200aef8(&e->pos, &self->target, range) != 0 && !near)) {
                vec_set(&self->target, ppos);
                self->state = 1;
                e->flags |= ENTITY_FLAG_200;
                return;
            }
            vec_set(&self->target, ppos);
            vec_dir(&dir2, ppos, &e->pos);
            if (near) {
                vec_scale(&dir2, fx_neg(&speed));
                func_0201812c(e, ppos, 1);
            } else {
                vec_scale(&dir2, speed);
                func_0201812c(e, ppos, 0);
            }
            if (!is_riding(e)) {
                func_02017ee4(e, &dir2, BLEND_4B);
            }
            e->flags &= ~ENTITY_FLAG_200;
            return;
    }
}
