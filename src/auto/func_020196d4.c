#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;
typedef struct {
    u16 v;
} HalfVal;
typedef struct {
    s32 x, y, z;
} Vec3;
typedef struct {
    s32 x, y, z;
} Pos;
typedef struct {
    s32 v;
} Fx;
typedef struct {
    Fx qy;
    Fx qx;
    Fx qz;
} Q;
typedef struct {
    Fx dx;
    Fx dy;
    Fx dz;
} D;
typedef struct {
    u16 a : 1;
    u16 b : 1;
    u16 rest : 14;
} Bits;

typedef struct Obj {
    u8 pad0[8];
    u32 flags;
    u8 pad1[0x54];
    Vec3 dir;
    u8 pad2[0x20];
    u8 mtx[0x24];
    Pos pos;
    u8 pad3[0xc];
    u16 rotX;
    u16 rotY;
    u8 pad4[4];
    u8 dirty;
    u8 changed;
    u8 pad5[0x7c];
    Bits bits;
    u8 pad6[0x71];
    u8 frozen;
    u8 pad7;
    u8 type;
    u8 pad8[2];
    u16 timer;
    u8 pad9[8];
    struct Obj *target;
} Obj;

enum {
    REG_SQRTCNT = 0x40002b0
};     /* NDS hardware square root unit */
enum {
    REG_SQRT_RESULT = 0x40002b4
};
enum {
    REG_SQRT_PARAM = 0x40002b8
};
enum {
    SQRT_MODE_64BIT = 1
};
enum {
    SQRT_BUSY = 0x8000
};
enum {
    TARGET_DROP_FLAGS = 0x802
};   /* target flags that make self drop the target */
enum {
    ROT_STEP = 0x38e
};            /* step argument of func_02098504 */

typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void obj_set_rot_y(Obj *o, HalfVal a) {
    if (o->rotY != a.v) {
        o->rotY  = a.v;
        o->dirty = 1;
    }
}

static inline void obj_set_rot_x(Obj *o, HalfVal a) {
    if (o->rotX != a.v) {
        o->rotX  = a.v;
        o->dirty = 1;
    }
}

extern void func_02010384(void *, UnkVal, ...);
extern void func_01ffa6f8(void *, void *);
extern void func_01ffa958(Vec3 *, const void *, const Vec3 *);
extern void func_02019554(void *);
extern s32 func_02098504(HalfVal *, HalfVal, HalfVal);
extern s16 func_020985d8(s32 a, s32 b);
extern u8 data_020f4d10[];

void func_020196d4(Obj *self, UnkVal arg1, ...) {
    Obj *target;
    s32 scale;
    HalfVal h1, h2, h3, h4;
    D d;
    Vec3 tmp;
    Vec3 look;
    Q q;
    s32 v0, v1, v2;
    HalfVal rot[2];

    func_02010384(self, arg1);
    if (self->frozen != 0) {
        if (self->bits.a == 1 && self->bits.b == 1) {
            self->flags |= 2;
        }
        return;
    }
    target = self->target;
    if (target != NULL) {
        if (target->flags & TARGET_DROP_FLAGS) {
            self->target = NULL;
        } else {
            scale    = data_020f4d10[self->type * 12] << 8;
            v2       = target->pos.z - self->pos.z;
            v1       = target->pos.y - self->pos.y;
            v0       = target->pos.x - self->pos.x;
            rot[1].v = self->rotY;
            d.dx.v   = v0;
            d.dy.v   = v1;
            d.dz.v   = v2;
            rot[0].v = self->rotX;
            q.qz     = d.dz;
            q.qx     = d.dx;
            h2.v     = ROT_STEP;
            h1.v     = func_020985d8(q.qx.v, q.qz.v);
            func_02098504(&rot[1], h1, h2);
            /* rounded horizontal distance: hardware sqrt of 4 * (dx * dx + dz * dz), then halved */
            {
                s64 t;
                t = (s64) d.dx.v * d.dx.v;
                t += (s64) d.dz.v * d.dz.v;
                *(vu16 *) REG_SQRTCNT    = SQRT_MODE_64BIT;
                *(vu64 *) REG_SQRT_PARAM = (u64) (t << 2);
            }
            while (*(vu16 *) REG_SQRTCNT & SQRT_BUSY) {
            }
            q.qy = d.dy;
            h3.v = -(u16) func_020985d8(q.qy.v, ((s32) * (vu32 *) REG_SQRT_RESULT + 1) >> 1);
            h4.v = ROT_STEP;
            func_02098504(&rot[0], h3, h4);
            obj_set_rot_y(self, rot[1]);
            obj_set_rot_x(self, rot[0]);
            if (self->dirty != 0) {
                self->changed = 1;
                self->dirty   = 0;
                func_01ffa6f8(self->mtx, &self->rotX);
            }
            look.x = 0;
            look.y = 0;
            look.z = scale;
            func_01ffa958(&tmp, self->mtx, &look);
            vec_set(&self->dir, &tmp);
        }
    }
    switch (self->type) {
        case 7:
            if (--self->timer == 0) {
                func_02019554(self);
            }
            break;
        default:
            if (--self->timer == 0) {
                self->flags |= 2;
            }
            break;
    }
}
