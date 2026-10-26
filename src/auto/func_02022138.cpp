#include "m2c.h"

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
    virtual void action(int, int, int, int); // Slot 0x24.
};

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0xb0];
    Vec3 pos;
} Obj;

typedef struct {
    s16 x, y, z;
} Vec3s;

extern "C" M2C_UNK data_020fd7a8;
extern "C" void func_02011384(void *);
extern "C" void *func_02015138(s32, s32, void *);
extern "C" void func_020223a0(void *);
extern "C" void func_0209f948(void *, UnkVal);
extern "C" void func_020accac(void *, Vec3 *, Vec3s *, Vec3 *);

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    s32 r;
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

extern "C" Entity *func_02022138(Entity *self) {
    u32 p148;
    s32 n;
    s32 half;
    UnkVal a;
    Vec3s rot;
    UnkVal b;
    Vec3 scale;
    u8 out[0x48];
    void *o;
    void *o2;
    Vec3 *src;

    func_02011384(self);
    M2C_FIELD(self, void **, 0)   = &data_020fd7a8;
    M2C_FIELD(self, u32 *, 0x22c) = 0;
    M2C_FIELD(self, u16 *, 0x1be) = 2;
    M2C_FIELD(self, u8 *, 0x1bc)  = 1;
    M2C_FIELD(self, u32 *, 0x220) = 0;
    M2C_FIELD(self, u32 *, 0x224) = 0;
    self->action(0x56, 0, 1, 0);
    self->action(0x8b, 0, 1, 0);
    M2C_FIELD(self, u16 *, 0x14e) = M2C_FIELD(self, u16 *, 0x14e) & ~1;
    p148                          = M2C_FIELD(self, u32 *, 0x148);
    n                             = p148 != 0 ? (s32) (M2C_FIELD(M2C_FIELD(p148, u32 *, 8), u16 *, 4) << 12) : 0;
    n                             = (n >> 12) - 1;
    half                          = n / 2;
    M2C_FIELD(self, s32 *, 0x21c) = n;
    M2C_FIELD(self, s32 *, 0x234) = half;
    M2C_FIELD(self, s32 *, 0x218) = half;
    a.v                           = half << 12;
    func_0209f948((u8 *) self + 0xd4, a);
    scale.x = 0x1000;
    scale.y = 0x1000;
    scale.z = 0x1000;
    rot.x   = 0;
    rot.y   = M2C_FIELD(self, u16 *, 0xca);
    rot.z   = 0;
    func_020accac(out, (Vec3 *) ((u8 *) self + 0xb0), &rot, &scale);
    o                               = func_02015138(0x14a, 0, out);
    M2C_FIELD(self, void **, 0x230) = o;
    src                             = &((Obj *) self)->pos;
    if (vec_ne(&((Obj *) o)->pos, src)) {
        vec_set(&((Obj *) o)->pos, src);
        M2C_FIELD(o, u8 *, 0xd1) = 1;
    }
    M2C_FIELD(self, Entity **, 0x230)->action(0x56, 0, 1, 0);
    M2C_FIELD(self, Entity **, 0x230)->action(0x8b, 0, 1, 0);
    o2                          = M2C_FIELD(self, void **, 0x230);
    M2C_FIELD(o2, u16 *, 0x14e) = M2C_FIELD(o2, u16 *, 0x14e) & ~1;
    b.v                         = M2C_FIELD(self, s32 *, 0x218) << 12;
    func_0209f948((u8 *) M2C_FIELD(self, void **, 0x230) + 0xd4, b);
    func_020223a0(self);
    return self;
}
