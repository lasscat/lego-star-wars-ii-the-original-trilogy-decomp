#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    void *vptr;
    s32 p0;
    s32 p1;
    s32 p2;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    s32 b0;
    s32 b1;
    s32 b2;
} Obj;

typedef struct {
    s32 min[3];
    s32 max[3];
} Box;

typedef struct {
    s32 a;
    s32 b;
} Res;

// Partial interface: unknown virtuals keep their observed vtable slots.
class Entity36AE8 {
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

    u8 pad04[0xb0 - 0x4];
    Vec3 pos;
    u8 pad_bc[0xca - 0xbc];
    u16 angle;
    u8 pad_cc[0x14e - 0xcc];
    u16 f14e_0 : 1;
    u16 f14e_1 : 1;
    u16 f14e_r : 14;
    u8 pad150[0x5d2 - 0x150];
    u16 f5d2;
};

typedef struct {
    void *vptr;
    Entity36AE8 *actor;
    u8 pad8[4];
    u8 flags;
    u8 state;
} Self;

extern "C" const s16 data_020f88c4[];
extern "C" M2C_UNK data_020fcd18;
extern "C" M2C_UNK data_020fe438;
typedef struct {
    u8 pad[0x384];
    s32 v;
} Inner;
typedef struct {
    u8 pad[0x68];
    Inner *in;
} Glob;
extern "C" Glob data_0210930c;

extern "C" void func_02007f24(s32 *out, f64 value);
extern "C" void func_0200af88(s8 *arg0, s8 arg1);
extern "C" void func_0204c594(Obj *o, void *src);
extern "C" void func_0204c6e8(Box *, Obj *);
extern "C" Res func_01ff9188(s32, Box *, Vec3 *);

enum {
    FX_ONE       = 0x1000, // 1.0 in 20.12.
    DELTA_Z      = 0x4000, // 4.0 in 20.12: z of the displacement before the heading turn.
    OBJ_KIND_BOX = 5,
    MIN_OVERLAP  = 0x2000,
};

// Half extent (0.5, 1.0, 0.5); the first converted value goes to z.
static inline void half_extent(Vec3 *v) {
    s32 a;
    s32 b;
    func_02007f24(&a, 0.5);
    func_02007f24(&b, 0.5);
    v->x = b;
    v->y = FX_ONE;
    v->z = a;
}

static inline void obj_base3(Obj *o, s32 x, s32 y, s32 z) {
    o->vptr = &data_020fcd18;
    o->p0   = x;
    o->p1   = y;
    o->p2   = z;
    o->f10  = 0;
    o->a0   = 0;
    o->a1   = 0;
    o->a2   = 0;
    o->sum  = 0;
}

// Rotate v in the x/z plane: x' = x*cos + z*sin, z' = z*cos - x*sin.
static inline void vec_rot_y(Vec3 *v, u16 ang) {
    s32 s;
    s32 c;
    s32 x;
    s32 z;
    s32 nx;
    s32 t;

    s  = data_020f88c4[(ang >> 4) * 2];
    c  = data_020f88c4[(ang >> 4) * 2 + 1];
    x  = v->x;
    z  = v->z;
    t  = (s32) (((s64) z * s + 0x800) >> 12);
    nx = (s32) (((s64) x * c + 0x800) >> 12);
    nx += t;
    t    = (s32) (((s64) x * s + 0x800) >> 12);
    t    = (s32) (((s64) z * c + 0x800) >> 12) - t;
    v->x = nx;
    v->z = t;
}

/* State step for the actor at self+4. State 0: a box object (vptr data_020fcd18, then
   data_020fe438) is built at the actor position raised by FX_ONE with half extent
   (0.5, 1.0, 0.5); its bounds and the displacement (0, 0, DELTA_Z) turned by the actor
   heading go to func_01ff9188 with the world at data_0210930c->+0x68->+0x384. Below
   MIN_OVERLAP the actor gets action 0x5e and state 1, else flag bit 0 is set. States 1, 2
   and 4 wait on actor bits (0x14e bit 1, 0x5d2 bit 0) and fire actions 0x5f and 0x60. */
extern "C" void func_02036ae8(Self *self) {
    Entity36AE8 *actor;
    Vec3 dir;
    Vec3 v;
    Obj o;
    Box box;
    s32 *p;
    s32 px;
    s32 py;
    s32 pz;

    switch (self->state) {
        case 0:
            dir.x = 0;
            dir.y = 0;
            dir.z = DELTA_Z;
            vec_rot_y(&dir, self->actor->angle);
            half_extent(&v);
            actor = self->actor;
            pz    = actor->pos.z;
            py    = actor->pos.y + FX_ONE;
            px    = actor->pos.x;
            obj_base3(&o, px, py, pz);
            func_0200af88((s8 *) &o.f24[0], -1);
            o.f24[2] = 0;
            o.vptr   = &data_020fe438;
            o.b0     = 0;
            o.b1     = 0;
            o.b2     = 0;
            o.f24[1] = OBJ_KIND_BOX;
            func_0204c594(&o, &v);
            p = (s32 *) &box;
            do {
                *p++ = 0;
            } while (p < (s32 *) (&box + 1));
            func_0204c6e8(&box, &o);
            if (func_01ff9188(data_0210930c.in->v, &box, &dir).b < MIN_OVERLAP) {
                self->actor->action(0x5e, 0, 1, 0);
                self->state = 1;
            } else {
                self->flags |= 1;
            }
            break;
        case 1:
            actor = self->actor;
            if (actor->f14e_1 == 1) {
                actor->action(0x5f, 1, 1, 0);
                self->state = 2;
            }
            break;
        case 2:
            actor = self->actor;
            if (actor->f5d2 & 1) {
                actor->action(0x60, 0, 1, 0);
                self->state = 4;
            }
            break;
        case 4:
            if (self->actor->f14e_1 == 1) {
                self->flags |= 1;
            }
            break;
    }
}
