#include "m2c.h"

class Vec3 {
public:
    s32 x;
    s32 y;
    s32 z;

    Vec3 &operator=(const Vec3 &o) {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }
        return *this;
    }
    Vec3() {}
    Vec3(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
    }
};

struct Fx;
extern "C" void func_020111c4(Fx *out, const Vec3 *v);

struct Fx {
    s32 v;
};

struct Angle {
    u16 v;

    Angle() {}
};

typedef struct {
    Angle x;
    Angle y;
    Angle z;
    Angle w;
} Rot;

typedef struct {
    s32 m[18];
} Mtx;

struct Sub {
    u8 pad0[0x4];
    Vec3 pos;
    u8 pad10[0x26 - 0x10];
    u8 active;
};

typedef struct {
    u8 pad0[0x20];
    Sub *sub;
    u8 pad24[0xb0 - 0x24];
    Vec3 pos;
} Target;

typedef struct {
    u8 pad0[0x28];
    Angle x;
    Angle y;
    Angle z;
} RotSrc;

class Obj {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 get_id(); // Slot 0x08.

    u8 pad4[0x8 - 0x4];
    u32 flags;
    u16 mode;
    u8 pade[0x30 - 0xe];
    RotSrc *rot_src;
    u8 pad34[0xb0 - 0x34];
    Vec3 pos;
    Vec3 scale;
    Rot rot;
    u8 padd0[0x182 - 0xd0];
    u16 kind;
    u8 pad184[0x5ce - 0x184];
    u8 pad5ce[0x5da - 0x5ce];
    u8 player;
};

typedef struct {
    u8 pad0[0x60];
    Vec3 vel;
    u8 pad6c[0x1bc - 0x6c];
    s32 id;
    u8 f1c0;
    u8 pad1c1;
    u8 f1c2;
} Spawn;

class VObj {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual s32 unknown1c(); // Slot 0x1c.
};

typedef struct {
    Vec3 pos;
    u16 yaw;
    u16 pitch;
    u8 id;
    u8 pad11[0x1c - 0x11];
} Msg;

typedef struct {
    u8 pad0[0xc28];
    u8 fc28;
} Cfg;

extern "C" s32 func_0204a880(void *arg0);
extern "C" s16 func_020985d8(s32 a, s32 b);
extern "C" void func_02098478(u16 *arg0, u32 arg1);
extern "C" void func_0200d4c8(Spawn *arg0, Vec3 *arg1);
extern "C" void *func_020187d0(void *self, s32 recordIndex, s32 arg2, s32 flag, s32 a4, Mtx *initialConfig, Target *a6);
extern "C" void func_02018ad8(void *obj, s32 useThirdRow);
extern "C" void *func_0205e80c(s32, s32, s32);
extern "C" u8 func_0208d294(void *self, u32 a1, void *a2, Angle a3, Angle a4, u8 a5, u8 a6, u8 a7, s32 a8);
extern "C" void func_020accac(Mtx *out, Vec3 *pos, Rot *rot, Vec3 *scale);
extern "C" void func_020b04f0(void *obj, u8 id, void *src, u8 size);
extern "C" void func_02007f24(s32 *out, f64 v);
extern "C" Spawn *func_0200cb48(void *self, s32 a1, s32 a2, Mtx *a3);

extern "C" s32 data_027e02a8;
extern "C" u8 data_02107950[];
extern "C" VObj *data_021092f4;
extern "C" Cfg data_02106d90;
extern "C" u8 data_0210794c[];
extern "C" const s16 data_020f88c4[];

static inline const Vec3 &sub_pos(const Sub *s) {
    return s->pos;
}

static inline void vec_copy(Vec3 *d, const Vec3 *s) {
    s32 x = s->x;
    s32 y = s->y;
    s32 z = s->z;
    d->z  = z;
    d->y  = y;
    d->x  = x;
}

static inline void vec_sub(Vec3 *r, const Vec3 *a, const Vec3 *b) {
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    r->x  = x;
    r->y  = y;
    r->z  = z;
}

static inline void angle_set(Angle *d, Angle s) {
    d->v = s.v;
}

static inline s16 atan_raw(Fx a, s32 b) {
    return func_020985d8(a.v, b);
}

static inline Angle fx_atan2(const Fx &a, Fx b) {
    Angle r;
    r.v = atan_raw(a, b.v);
    return r;
}

static inline Angle fx_atan2_neg(const Fx &a, s32 b) {
    Angle r;
    r.v = -(u16) atan_raw(a, b);
    return r;
}

/* Null-safe read of an Fx value (0 when there is none). */
static inline s32 fx_val(const Fx &r) {
    const Fx *p = &r;
    s32 v       = 0;
    if (p) {
        v = p->v;
    }
    return v;
}

/* Rotates (x, z) of v about the Y axis by a using the sin/cos table, 20.12 rounding. */
static inline void vec_roty(Vec3 *v, u16 a) {
    s32 s = data_020f88c4[(a >> 4) * 2];
    s32 c = data_020f88c4[(a >> 4) * 2 + 1];
    s32 x = v->x;
    s32 z = v->z;
    s32 nx;
    s32 t;
    t  = (s32) (((s64) z * s + 0x800) >> 12);
    nx = (s32) (((s64) x * c + 0x800) >> 12);
    nx += t;
    v->x = nx;
    t    = (s32) (((s64) x * s + 0x800) >> 12);
    t    = (s32) (((s64) z * c + 0x800) >> 12) - t;
    v->z = t;
}

static inline s32 obj_id(Obj *o) {
    return o->get_id();
}

enum {
    LEN_MIN = 0x199
};
enum {
    REG_SQRTCNT     = 0x040002B0,
    REG_SQRT_RESULT = 0x040002B4,
    REG_SQRT_PARAM  = 0x040002B8
};
enum {
    SQRT_BUSY = 0x8000
};
enum {
    KIND_66 = 0x66
};
enum {
    TYPE_D = 0xd
};
enum {
    FX_ONE = 0x1000
};

/* Builds a rotation from obj (aimed at target's or its sub-object's position when given),
 * then either spawns an object (type 0xd: size 0x1e0 via func_0200cb48, launched along the
 * aim yaw; else size 0x1d4 via func_020187d0) and returns it, or, when spawning is
 * suppressed, forwards the request through func_0208d294 / func_020b04f0 and returns 0. */
extern "C" void *func_02010c6c(Obj *obj, s32 type, s32 arg2, s32 arg3, s32 arg4, Vec3 *pos, Target *target, u8 arg7) {
    Mtx mtx1;
    Mtx mtx2;
    Vec3 tpos;
    Vec3 diff;
    Msg msg;
    Vec3 scale;
    Vec3 vel;
    Rot rot;
    Fx len;
    s32 fy;
    s32 fz;
    u8 local;

    rot.x = obj->rot.x;
    rot.y = obj->rot.y;
    rot.z = obj->rot.z;
    rot.w = obj->rot.w;
    local = 0;
    if (obj->mode == 1 && func_0204a880(&obj->pad5ce) != 0) {
        local = 1;
    }

    if (target != 0) {
        s32 has = 0;
        Sub *sub;
        vec_copy(&tpos, &target->pos);
        sub = target->sub;
        if (sub != 0 && sub->active != 0) {
            has = 1;
        }
        if (has) {
            tpos = sub_pos(sub);
        }
        vec_sub(&diff, &tpos, pos);
        func_020111c4(&len, &diff);
        if (fx_val(len) >= LEN_MIN) {
            s64 t;
            s32 mag;
            angle_set(&rot.y, fx_atan2(*(Fx *) &diff.x, *(Fx *) &diff.z));
            t = (s64) diff.x * diff.x;
            t += (s64) diff.z * diff.z;
            *(volatile u16 *) REG_SQRTCNT = 1;
            *(u64 *) REG_SQRT_PARAM       = t << 2;
            while (*(volatile u16 *) REG_SQRTCNT & SQRT_BUSY) {
            }
            mag = ((s32) * (volatile u32 *) REG_SQRT_RESULT + 1) >> 1;
            angle_set(&rot.x, fx_atan2_neg(*(Fx *) &diff.y, mag));
        }
    }

    if (arg2 != 0) {
        func_02098478(&rot.y.v, arg2);
    }
    if (obj->kind == KIND_66) {
        RotSrc *src = obj->rot_src;
        angle_set(&rot.x, src->x);
        angle_set(&rot.y, src->y);
        angle_set(&rot.z, src->z);
    }

    if ((data_027e02a8 & 0x40) == 0 || arg7 != 0) {
        if (type == TYPE_D) {
            Spawn *e = (Spawn *) func_0205e80c(0x1e0, 3, 4);
            if (e != 0) {
                scale.x = FX_ONE;
                scale.y = FX_ONE;
                scale.z = FX_ONE;
                func_020accac(&mtx1, pos, &rot, &scale);
                e = func_0200cb48(e, 0x226, 0, &mtx1);
            }
            e->f1c2 = 1;
            if (local) {
                e->f1c0 = 1;
                e->id   = obj->player;
            } else {
                e->id = obj_id(obj);
            }
            func_02007f24(&fz, 2.8);
            func_02007f24(&fy, 1.0);
            e->vel = Vec3(0, fy, fz);
            vec_roty(&e->vel, rot.y.v);
            func_0200d4c8(e, &obj->pos);
            return 0;
        } else {
            Spawn *e = (Spawn *) func_0205e80c(0x1d4, 3, 4);
            if (e != 0) {
                s32 flag;
                func_020accac(&mtx2, pos, &rot, &obj->scale);
                flag = 1;
                if (obj->flags & 0x80000000) {
                    flag = 0;
                }
                e = (Spawn *) func_020187d0(e, type, arg3, local, flag, &mtx2, target);
            }
            func_02018ad8(e, 1);
            if (local) {
                e->id = arg4;
            } else {
                e->id = obj_id(obj);
            }
            return e;
        }
    }
    if (data_02106d90.fc28 != 0) {
        s32 id = obj_id(obj);
        u8 r   = func_0208d294(data_02107950, id, &obj->scale, rot.x, rot.y, type, arg3, arg4, obj->mode == 1);
        if (data_021092f4->unknown1c() == 0) {
            msg.pos.x = pos->x;
            msg.pos.y = pos->y;
            msg.pos.z = pos->z;
            msg.yaw   = rot.y.v;
            msg.pitch = rot.x.v;
            msg.id    = r;
            func_020b04f0(data_0210794c, 0xe, &msg, 0xff);
        }
    }
    return 0;
}
