#include "m2c.h"

extern "C" {

typedef volatile u16 vu16;
typedef volatile u32 vu32;

struct Fx {
    s32 v;
    Fx() {}
    s32 get() const {
        return v;
    }
};

struct VecFx {
    Fx x;
    Fx y;
    Fx z;
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Angle;

struct W {
    s32 v;
    W() {}
};

class Obj {
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
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual W query(int); // Slot 0x3c.

    u8 pad04[4];
    u32 flags;
    u8 pad0c[0xa4];
    Vec3 pos;
    u8 padbc[0xe];
    u16 angle;
    u8 padcc[4];
    u8 dirty;
};

typedef struct {
    u8 pad00[4];
    Obj *obj;
    u8 pad08[5];
    u8 state;
    u8 pad0e[2];
    Vec3 target;
    Vec3 saved;
    s32 f28;
    s32 f2c;
} Ctl;

extern void func_0201812c(Obj *, Vec3 *, s32);
extern s16 func_020985d8(s32, s32);

enum {
    REG_SQRTCNT     = 0x040002b0,
    REG_SQRT_RESULT = 0x040002b4,
    REG_SQRT_PARAM  = 0x040002b8,
    SQRTCNT_64BIT   = 1,
    SQRTCNT_BUSY    = 0x8000,
};

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

/*
 * Heading of the horizontal offset (x, z). func_020985d8 is the atan2-style routine
 * (octant reduction on the signs/sizes of its two inputs, FX_Div ratio, table data_020f72b8)
 * that the matched func_0203180c.cpp and func_020344f0.cpp also use for headings.
 * Matching note: fx_atan2 copies z by value and fx_atan2_raw copies x by value. This nesting
 * gives the target's dead stack copies: z stored first at sp+0xc, then x at sp+0x8.
 */
static inline s16 fx_atan2_raw(Fx x, const Fx &z) {
    return func_020985d8(x.get(), z.get());
}

static inline Angle fx_atan2(const Fx &x, Fx z) {
    Angle a;
    a.v = fx_atan2_raw(x, z);
    return a;
}

static inline void set_angle(Obj *obj, Angle a) {
    if (obj->angle != a.v) {
        obj->angle = a.v;
        obj->dirty = 1;
    }
}

/*
 * Called through the pointer table data_020fdeec. Clears flag 0x200 on self->obj, calls
 * func_0201812c(obj, &self->target, 0), then measures the horizontal (x/z, y = 0)
 * distance from obj->pos to self->target with the hardware square root.
 * If that distance exceeds self->f2c: set obj's angle (0xca) to the heading of the offset
 * toward the target (byte 0xd0 is set to 1 only when the angle changes), copy obj->pos
 * into self->saved, set self->f28 = min(obj->query(6), distance - self->f2c) (vtable
 * slot 0x3c, returned through a hidden pointer), call obj->action(6, 1, 0, 0) (slot 0x24)
 * and set state 1.
 * Otherwise set state 4. The roles of flag 0x200, the value 6 and states 1/4 are unknown.
 */
void func_02034054(Ctl *self) {
    VecFx delta;
    W w;
    s32 dz, dx;
    s32 dist, root;
    s64 dist_sq;
    Obj *obj;
    Vec3 *pos;

    self->obj->flags &= ~0x200;
    func_0201812c(self->obj, &self->target, 0);
    obj       = self->obj;
    dz        = self->target.z - obj->pos.z;
    dx        = self->target.x - obj->pos.x;
    delta.x.v = dx;
    delta.z.v = dz;
    delta.y.v = 0;
    dist_sq   = (s64) dx * dx;
    dist_sq += (s64) delta.y.v * delta.y.v;
    dist_sq += (s64) dz * dz;

    /* 64-bit hardware sqrt of 4 * dist_sq gives 2 * distance; (root + 1) >> 1 rounds it. */
    *(vu16 *) REG_SQRTCNT   = SQRTCNT_64BIT;
    *(u64 *) REG_SQRT_PARAM = dist_sq << 2;
    while (*(vu16 *) REG_SQRTCNT & SQRTCNT_BUSY) {
    }
    root = *(vu32 *) REG_SQRT_RESULT;
    dist = (root + 1) >> 1;

    if (dist > self->f2c) {
        set_angle(self->obj, fx_atan2(delta.x, delta.z));
        obj = self->obj;
        pos = &obj->pos;
        vec_set(&self->saved, pos);
        w         = self->obj->query(6);
        self->f28 = w.v;
        if (dist - self->f2c < self->f28) {
            self->f28 = dist - self->f2c;
        }
        self->obj->action(6, 1, 0, 0);
        self->state = 1;
    } else {
        self->state = 4;
    }
}
}
