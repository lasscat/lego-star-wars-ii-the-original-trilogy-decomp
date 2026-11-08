#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;
/* Binary angle: 0x10000 is a full turn. */
struct Angle {
    u16 value;
    Angle() {}
    Angle(u16 v) :
        value(v) {}
    /* By-value assignment: keeps the stored copy of the heading the original makes. */
    void operator=(Angle o) {
        value = o.value;
    }
};
typedef struct {
    s32 v;
} Fx;
/* Stack frame of func_020344f0 in its original slot order. m is the 0x48-byte
 * transform record filled by func_020accac (translation +0x24, scale +0x30,
 * rotation +0x3c). */
typedef struct {
    Fx qx;
    Fx qz;
    u16 rot[3];
    Vec3 scl;
    Vec3 dir;
    Vec3 pos;
    Vec3 zero;
    u8 m[0x48];
} Q;
class Effect {
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
    virtual void unknown24(s32, s32, s32, s32);
};

typedef struct Actor {
    u8 pad0[8];
    u32 f8;
    u8 padc[0x24];
    struct Actor *f30;
    u8 pad34[0x7c];
    Vec3 pos;
    u8 padbc[0xe];
    Angle yaw;
} Actor;

typedef struct {
    u8 pad0[4];
    Actor *f4;
    u8 pad8[0x17];
    u8 f1f;
    u8 pad20[0x11];
    u8 f31;
    u8 f32;
    u8 f33;
    u8 pad34[0x12];
    Angle f46;
    Actor *f48;
    Effect *f4c;
    void *f50;
} Obj;

extern "C" u32 func_02062ae4(s32);
extern "C" void func_0202fbbc(void *, s32, s32);
extern "C" Actor *func_0203180c(void *, s32, s32, s32, Angle, Angle);
extern "C" u16 func_020985d8(s32, s32);
extern "C" void *func_0205e80c(s32, s32, s32);
extern "C" void func_020accac(void *, void *, void *, void *);
extern "C" void *func_0200ff50(void *, s32, s32, s32, void *);
extern "C" void *func_020b95bc(s32, void *);

static inline void vec_sub(Vec3 *o, const Vec3 *a, const Vec3 *b) {
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    o->x  = x;
    o->y  = y;
    o->z  = z;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void set_f46(Obj *o, Angle v) {
    o->f46 = v;
}
enum {
    TARGET_MASK        = 3,
    TARGET_RADIUS      = 100,
    ELEVATION_LIMIT_60 = 0x2aaa,
    YAW_LIMIT_30_DEG   = 0x1555,
    FX32_ONE           = 0x1000,
    SPAWN_SIZE         = 0x1bc,
};

/* Heading (func_020985d8 on x, z) of a horizontal offset. */
static inline Angle Atan2(const Fx &z, const Fx &x) {
    return Angle(func_020985d8(x.v, z.v));
}
/* |a - b| as a signed 16-bit angle difference, below limit. */
static inline bool Within(Angle a, Angle b, Angle limit) {
    s32 d = (s16) (u16) (a.value - b.value);
    if (d < 0) {
        d = -d;
    }
    return (u16) d < limit.value;
}
/* 1 when bit 31 of the flags word is clear, else 0. */
static inline s32 sign_clear_flag(u32 f) {
    s32 r = 1;
    if (f & 0x80000000) {
        r = 0;
    }
    return r;
}

/*
 * Per-tick update of a controller (self->f4 is its actor, as in func_0203180c).
 * f32 counts down each tick; when it is already 0, f31 is reset to 3. f1f is
 * a delay: while nonzero it is decremented and nothing else happens.
 * Once the delay has run out:
 *  - f33 == 0: with a 1-in-31 chance (func_02062ae4(30) returns 0..30)
 *    func_0202fbbc(self, 0, -1) is called, the delay set to 16 and 1 returned.
 *  - otherwise func_0203180c picks the nearest actor of kind mask 3 within
 *    radius 100 (yaw cone of its own, elevation within 60 degrees of level).
 *    If its horizontal heading from the controller's actor is within 30
 *    degrees of that actor's yaw, then with chance (func_02062ae4(100) <
 *    chance) a 0x1bc-byte object is allocated (func_0205e80c), constructed by
 *    func_0200ff50 at the actor's position (or at f30's position when f30 is
 *    set) with unit scale, stored in f4c and its slot-0x24 virtual called;
 *    f48 keeps the target, f50 gets func_020b95bc(8, actor), f46 is cleared.
 *    Without that chance func_0202fbbc(self, target, -1) is called and 1
 *    returned. Either way f32 restarts at 50 and f31 counts one use: the
 *    delay becomes 16, or 90 (f31 back to 3) after the last one.
 * Returns 1 when func_0202fbbc was called, else 0.
 */
extern "C" s32 func_020344f0(Obj *self, u32 chance) {
    s32 ret = 0;
    u8 c;
    void *spawned;
    Actor *target;
    Q q;
    Angle ang;

    if (self->f32 == 0) {
        self->f31 = 3;
    } else {
        self->f32 = self->f32 - 1;
    }
    c = self->f1f;
    if (c == 0) {
        if (self->f33 == 0) {
            if (func_02062ae4(30) == 0) {
                func_0202fbbc(self, 0, -1);
                self->f1f = 16;
                ret       = 1;
            }
        } else {
            target   = func_0203180c(self, TARGET_MASK, TARGET_RADIUS, 1, Angle(0), Angle(ELEVATION_LIMIT_60));
            q.zero.x = 0;
            q.zero.y = 0;
            q.zero.z = 0;
            if (target != NULL) {
                /* Offset from the controller's actor to the target. */
                vec_sub(&q.dir, &target->pos, &self->f4->pos);
                vec_set(&q.zero, &q.dir);
                q.qz.v = q.zero.z;
                q.qx.v = q.zero.x;
                ang    = Atan2(q.qz, q.qx);
                if (Within(ang, self->f4->yaw, Angle(YAW_LIMIT_30_DEG))) {
                    if (chance != 0 && func_02062ae4(100) < chance) {
                        Actor *me = self->f4;
                        Actor *p  = me->f30;
                        q.pos.x   = me->pos.x;
                        q.pos.y   = me->pos.y;
                        q.pos.z   = me->pos.z;
                        if (p != NULL) {
                            vec_set(&q.pos, (Vec3 *) ((u8 *) p + 4));
                        }
                        self->f48 = target;
                        spawned   = func_0205e80c(SPAWN_SIZE, 3, 4);
                        if (spawned != NULL) {
                            q.rot[0] = 0;
                            q.rot[1] = 0;
                            q.rot[2] = 0;
                            q.scl.x  = FX32_ONE;
                            q.scl.y  = FX32_ONE;
                            q.scl.z  = FX32_ONE;
                            func_020accac(q.m, &q.pos, q.rot, &q.scl);
                            spawned = func_0200ff50(spawned, 8, 0x215, sign_clear_flag(self->f4->f8), q.m);
                        }
                        self->f4c = (Effect *) spawned;
                        self->f4c->unknown24(0, 0, 1, 0);
                        self->f50 = func_020b95bc(8, self->f4);
                        set_f46(self, Angle(0));
                    } else {
                        func_0202fbbc(self, (s32) target, -1);
                        ret = 1;
                    }
                    self->f32 = 50;
                    self->f31 = self->f31 - 1;
                    if (self->f31 != 0) {
                        self->f1f = 16;
                    } else {
                        self->f31 = 3;
                        self->f1f = 90;
                    }
                }
            }
        }
    } else {
        self->f1f = c - 1;
    }
    return ret;
}
