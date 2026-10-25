/* Reconstructed from USA ARM9 at 0x0203764c (2712 bytes).
 *
 * func_0203764c(obj) resets an actor controller: it restores the default
 * animation/sound for the actor type, refreshes per-slot state, resets the
 * velocity and, for player 1, converts a stored amount into 1000/500/100
 * coin pickups spawned from a point in front of the actor.
 *
 * C++: virtual calls on the actor (slots 0x24, 0x30, 0x34) and on the
 * sub-object at +0xd4 (slot 0x08), as in func_0200636c.cpp.  Virtual
 * methods are declarations only; callees and data use extern "C".
 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec;

typedef struct {
    s32 value;
} Fixed;

typedef struct {
    Fixed x, y, z;
} Scale;

class SubObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void f8(void *, s32, s32, s32);
};

class ActorBase {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void f24(s32, s32, s32, s32);
    virtual void v28();
    virtual void v2c();
    virtual void setAnim(s32, s32);
    virtual void f34(s32);
};

struct Actor : public ActorBase {
    u8 pad4[0x4];
    s32 flags;
    u16 kind;
    u8 padE[0x52];
    Vec v60;
    u8 pad6C[0x18];
    s32 f84;
    u8 pad88[0x4];
    u8 mtx[0x24];
    Vec pos;
    Scale scale;
    u8 rot[0x8];
    u8 dirty;
    u8 fd1;
    u8 padD2[0x2];
    SubObj sub;
    u8 fd8[0xa8];
    u16 type;
    u8 pad182[0x458];
    u8 f5da;
    u8 pad5DB[0xe0];
    u8 f6bb;
};

typedef struct {
    u8 pad0[0x4];
    Actor *actor;
    u8 pad8[0x5];
    u8 state;
    u8 padE[0x4];
    u8 f12;
} Obj;

typedef struct {
    u16 anim;
    u8 pad2[0x16];
} AnimEntry;

typedef struct {
    u8 pad0[0x3];
    u8 item;
    u8 pad4;
} CharEntry;

typedef struct {
    u8 pad0[0x8];
} TypeEntry;

typedef struct {
    u8 pad0[0xc];
} SaveEntry;

typedef struct {
    u8 pad0[0x28];
    u8 f28;
} ItemInfo;

extern "C" AnimEntry data_020ef57c[];
extern "C" Vec data_020ff9b4;
extern "C" M2C_UNK data_021093b0;
extern "C" M2C_UNK data_0210930c;
extern "C" CharEntry data_020eebb8[];
extern "C" TypeEntry data_020eb7b8[];
extern "C" u8 data_021027f8[];
extern "C" SaveEntry data_02104d94[];

extern "C" u16 func_0201ca1c(u16);
extern "C" void func_020ab40c(void *, u16);
extern "C" void func_0201c778(Vec *);
extern "C" void func_02006220(Actor *, Vec *);
extern "C" void func_020ab574(void *, Vec *, s32);
extern "C" s32 func_02062b3c(s32);
extern "C" void func_02007f24(Fixed *, f64);
extern "C" void func_02094bf0(void *, Vec *, Vec *, s32);
extern "C" void func_0200c834(Actor *, u8);
extern "C" void func_0200ca38(Actor *);
extern "C" u8 func_020917b4(void *);
extern "C" s32 func_02093fa8(u8);
extern "C" s32 func_02093fd0(u8);
extern "C" ItemInfo *func_0208dad8(u16);
extern "C" void *func_02010c0c(TypeEntry *, s32);
extern "C" void func_020b8f70(s32, s32);
extern "C" void func_020b95bc(s32, Actor *);
extern "C" s32 func_0208559c(SaveEntry *);
extern "C" void func_01ffa6f8(void *, void *);
extern "C" void func_01ffa958(Vec *, void *, Vec *);
extern "C" void func_020855ac(SaveEntry *, s32);
extern "C" void func_020380e4(Obj *);

static inline Vec *initVec(Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

static inline void VecSub(const Vec *a, const Vec *b, Vec *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

static inline s64 VecDot64(const Vec *a, const Vec *b) {
    s64 t = (s64) a->x * b->x;
    t += (s64) a->y * b->y;
    t += (s64) a->z * b->z;
    return t;
}

static inline void VecCopy(const Vec *src, Vec *dst) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
}

static inline s32 multiplyFixed(s32 value, const Fixed &scale) {
    return (s32) (((s64) value * scale.value + 0x800) >> 12);
}

static inline void scaleVector(Vec *v, const Fixed *s) {
    Fixed x = *s;
    v->x    = multiplyFixed(v->x, x);
    Fixed y = *s;
    v->y    = multiplyFixed(v->y, y);
    Fixed z = *s;
    v->z    = multiplyFixed(v->z, z);
}

static inline void VecNormalize(Vec *v) {
    s64 t;
    s32 sqrt;
    s64 div;

    if (v->x == 0 && v->y == 0 && v->z == 0) {
        VecCopy(&data_020ff9b4, v);
        return;
    }
    t = VecDot64(v, v);

    *(volatile u16 *) 0x04000280 = 2;
    *(volatile u64 *) 0x04000290 = 1LL << 56;
    *(volatile u64 *) 0x04000298 = t;

    *(volatile u16 *) 0x040002B0 = 1;
    *(u64 *) 0x040002B8          = t << 2;

    while (*(volatile u16 *) 0x040002B0 & 0x8000) {
    }
    sqrt = (s32) * (volatile u32 *) 0x040002B4;

    while (*(volatile u16 *) 0x04000280 & 0x8000) {
    }
    div = (s64) * (u64 *) 0x040002A0;

    div *= sqrt;

    v->x = (s32) ((div * v->x + (1LL << 44)) >> 45);
    v->y = (s32) ((div * v->y + (1LL << 44)) >> 45);
    v->z = (s32) ((div * v->z + (1LL << 44)) >> 45);
}

static inline void ActorLocalToWorld(Actor *a, Vec *in, Vec *out) {
    if (a->dirty) {
        a->fd1   = 1;
        a->dirty = 0;
        func_01ffa6f8(a->mtx, a->rot);
    }
    func_01ffa958(out, a->mtx, in);
    if (a->scale.x.value != 0x1000 || a->scale.y.value != 0x1000 || a->scale.z.value != 0x1000) {
        Fixed x = a->scale.x;
        out->x  = multiplyFixed(out->x, x);
        Fixed y = a->scale.y;
        out->y  = multiplyFixed(out->y, y);
        Fixed z = a->scale.z;
        out->z  = multiplyFixed(out->z, z);
    }
    out->x += a->pos.x;
    out->y += a->pos.y;
    out->z += a->pos.z;
}

extern "C" void func_0203764c(Obj *obj) {
    u32 anim;
    s32 snd;
    s32 i;
    s32 j;
    s32 n;
    u8 c;
    Actor *a;
    Vec tmp;
    Vec pos;
    Vec vel;
    Vec tmp2;
    Vec base;
    Vec pt;
    Vec dir;
    s32 counts[3];
    Vec off;
    Fixed rnd;
    Fixed speed;
    s32 amount;
    s32 rem;
    void *res;
    s32 item;

    obj->state = 0;
    anim       = 0x201;
    snd        = 0x1e;
    if (obj->actor->type == 0x11) {
        c = obj->actor->f6bb;
        if ((c <= 0x48 || c > 0x4e) && c != 0x48) {
            obj->actor->setAnim(data_020ef57c[c].anim, 0);
            a = obj->actor;
            func_020ab40c(a->fd8, func_0201ca1c(a->type));
            func_0201c778(&tmp);
            func_02006220(obj->actor, &tmp);
            func_020ab574(obj->actor->fd8, &tmp, 1);
        }
    }

    if (obj->actor->kind == 2 && func_02062b3c(0x32) != 0) {
        a     = obj->actor;
        pos.x = a->pos.x;
        pos.y = a->pos.y;
        pos.z = a->pos.z;
        pos.y += 0x9000;
        vel.x = data_020ff9b4.x;
        vel.y = data_020ff9b4.y;
        vel.z = data_020ff9b4.z;
        func_02007f24(&rnd, -0.75);
        vel.y = rnd.value;
        func_02094bf0(&data_021093b0, &pos, &vel, 3);
    }

    switch (obj->actor->type) {
        case 5:
            anim = 0x203;
            break;
        case 11:
            anim = 0x204;
            break;
        case 20:
            anim = 0x20b;
            break;
        case 21:
            anim = 0x20c;
            break;
        case 7:
            anim = 0x21a;
            break;
        case 1:
            anim = 0x205;
            break;
        case 2:
        case 3:
            func_0201c778(&tmp2);
            obj->actor->setAnim(0, 0);
            a = obj->actor;
            func_020ab40c(a->fd8, func_0201ca1c(a->type));
            func_02006220(obj->actor, &tmp2);
            func_020ab574(obj->actor->fd8, &tmp2, 1);
            obj->actor->f34(1);
            anim = 0x201;
            break;
        case 8:
            anim = 0x202;
            break;
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 31:
        case 34:
        case 35:
            anim = 0x21b;
            snd  = 0xbc;
            break;
        case 10:
            anim = 0x206;
            snd  = 0xbc;
            break;
        case 32:
        case 33:
            anim = 0x21a;
            snd  = 0x9f;
            break;
        case 18:
            anim = 0x207;
            snd  = 0xc9;
            break;
        case 19:
            anim = 0x208;
            break;
        case 12:
            anim = 0x209;
            break;
        case 13:
            anim = 0x20a;
            snd  = 0xc9;
            break;
        case 4:
            anim = 0x276;
            snd  = 0x7a;
            break;
        case 6:
            anim = 0x276;
            break;
        case 29:
        case 30:
            anim = 0x276;
            snd  = 0xc9;
            break;
        case 9:
            anim = 0x21a;
            break;
        case 17:
            obj->f12 = 1;
            snd      = 0x3b;
            func_0200c834(obj->actor, 2);
            func_0200c834(obj->actor, 3);
            break;
    }

    switch ((u32) obj->actor->f6bb) {
        case 0x11:
            snd = 0x3b;
            break;
        case 0x1f:
            snd = 0x4b;
            break;
        case 0x35:
        case 0x36:
            snd = 0x7a;
            break;
        case 0x42:
            snd = 0xb2;
            break;
        case 0x10:
        case 0x43:
            snd = 0x2d;
            break;
    }

    switch (anim) {
        case 0x201:
        case 0x202:
            break;
        default:
            func_0200ca38(obj->actor);
            break;
        case 0x21a:
        case 0x21b:
            switch (func_02093fa8(func_020917b4(&data_0210930c))) {
                case 0:
                case 1:
                    anim = 0x21a;
                    break;
                case 2:
                    anim = 0x21b;
                    break;
            }
            break;
    }

    if (anim != 0x276 && obj->f12 == 0) {
        obj->actor->setAnim(anim, 1);
        obj->actor->flags &= ~0x4000;
        obj->actor->f34(1);
    }

    for (i = 0; i < 12; i++) {
        if (i != 2 && i != 3) {
            func_0200c834(obj->actor, i);
        }
    }

    {
        CharEntry *e = &data_020eebb8[obj->actor->f6bb];
        item         = e->item;
    }
    if (item != 0xfa && func_0208dad8(item)->f28 != 0) {
        res = func_02010c0c(&data_020eb7b8[obj->actor->type], 0x78);
        if (res != 0) {
            obj->actor->sub.f8(res, 0, 1, 0);
        }
    }

    if (obj->f12 == 0) {
        obj->actor->f24(0x35, 0, 1, 0);
        if (snd != 0xc9) {
            if (obj->actor->f5da == data_021027f8[0x2a]) {
                func_020b8f70(snd, 0);
            } else {
                func_020b95bc(snd, obj->actor);
            }
        }
    }

    VecCopy(&data_020ff9b4, &obj->actor->v60);
    obj->actor->flags |= 0x800;
    obj->actor->f84 = 0x1d;
    if (obj->actor->kind != 1) {
        return;
    }

    if (func_02093fd0(func_020917b4(&data_0210930c)) != 0x10) {
        n = func_0208559c(&data_02104d94[obj->actor->f5da]) << 12;
        if (n > 0) {
            if (n <= 0x1f4000) {
                n = 0x64000;
            } else {
                n = (s32) (((s64) n * 0x199 + 0x800) >> 12);
                n -= ((n >> 12) % 100) << 12;
            }

            a      = obj->actor;
            base.x = a->pos.x;
            base.y = a->pos.y;
            base.z = a->pos.z;
            ActorLocalToWorld(obj->actor, initVec(&off, 0, 0, 0x1000), &pt);
            VecSub(&pt, &base, &dir);
            VecNormalize(&dir);

            speed.value = 0x2000;
            scaleVector(&dir, &speed);
            base.y += 0x8000;
            amount    = n >> 12;
            counts[2] = amount / 1000;
            rem       = amount - counts[2] * 1000;
            counts[1] = rem / 500;
            counts[0] = (rem - counts[1] * 500) / 100;

            for (s32 k = 0; k < 3; k++) {
                for (j = 0; j < counts[k]; j++) {
                    func_02094bf0(&data_021093b0, &base, &dir, k);
                }
            }
            func_020855ac(&data_02104d94[obj->actor->f5da], -amount);
        }
    }
    func_020380e4(obj);
}
