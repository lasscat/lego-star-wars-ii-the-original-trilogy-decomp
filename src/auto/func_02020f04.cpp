#include "m2c.h"

struct Vec3 {
    s32 x, y, z;
    Vec3() {}
    bool operator!=(const Vec3 &o) const {
        bool r = false;
        if (x != o.x || y != o.y || z != o.z) {
            r = true;
        }
        return r;
    }
    Vec3 &operator=(const Vec3 &o) {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }
        return *this;
    }
};

extern "C" const s16 data_020f88c4[];
extern "C" u32 data_020fd670;

inline s32 FxMul(s32 a, s32 b) {
    s64 t = a;
    t     = (t * b + 0x800) >> 12;
    return (s32) t;
}

struct Sub {
    u8 pad0[0x24];
    Vec3 pos; // 0x24
    u8 pad30[0x45 - 0x30];
    u8 dirty; // 0x45
    u8 pad46[0x39c - 0x46];
    u8 f39c;
    void SetPos(const Vec3 &p) {
        if (pos != p) {
            pos   = p;
            dirty = 1;
        }
    }
};

struct Self {
    void *vptr;
    u8 pad4[0xb0 - 4];
    Vec3 pos; // 0xb0
    u8 padbc[0xca - 0xbc];
    u16 angle; // 0xca
    u8 padcc[0x216 - 0xcc];
    u8 f216;
    u8 pad217;
    Sub *sub; // 0x218
};

extern "C" Self *func_02011384(Self *self, s32 a, s32 b, s32 c);
extern "C" void *func_0205e80c(u32 size, s32 heap, s32 align);
extern "C" Sub *func_020bbfe8(Sub *self);
extern "C" s32 func_0205ab44(s32);
extern "C" s32 func_0205ab58(s32);
extern "C" void func_020bbeb0(Sub *, s32);
extern "C" void func_020bbf78(Sub *, s32, s32, s32);
extern "C" void func_020bc4cc(Sub *, s32);

enum {
    CHILD_SIZE = 0x3a0
};
enum {
    FX_SEVEN = 0x7000
}; // 7.0 in 20.12 fixed point

// Runs the base initialiser func_02011384 (type 10), installs the vtable at
// data_020fd670 and clears +0x216. Allocates a 0x3a0-byte child through
// operator new (func_0205e80c, heap 3, align 4) and its constructor
// func_020bbfe8, binds it to ids 0x1150 and 0xf8c, then places it at
// self->pos + (sin * 7.0, 7.0, cos * 7.0) with the angle index +0xca >> 4
// (child +0x45 is set only when the position changes). Finishes with
// func_020bc4cc(child, 1) and clears child +0x39c.
extern "C" Self *func_02020f04(Self *self, s32 a1, s32 a2) {
    func_02011384(self, 10, a1, a2);
    self->vptr = &data_020fd670;
    self->f216 = 0;
    Sub *sub   = (Sub *) func_0205e80c(CHILD_SIZE, 3, 4);
    if (sub != 0) {
        sub = func_020bbfe8(sub);
    }
    self->sub = sub;
    func_020bbeb0(self->sub, func_0205ab44(0x1150));
    func_020bbf78(self->sub, 0xf8c, func_0205ab58(0xf8c), 0);
    int i;
    const Vec3 *p;
    s32 dx;
    s32 dz;
    s32 r;
    Vec3 v;
    s32 cs;
    s32 sn;
    p   = &self->pos;
    i   = self->angle >> 4;
    r   = FX_SEVEN;
    sn  = data_020f88c4[i * 2];
    cs  = data_020f88c4[i * 2 + 1];
    dx  = FxMul(sn, r);
    dz  = FxMul(cs, r);
    v.z = p->z + dz;
    v.y = p->y + FX_SEVEN;
    v.x = p->x + dx;
    self->sub->SetPos(v);
    func_020bc4cc(self->sub, 1);
    self->sub->f39c = 0;
    return self;
}
