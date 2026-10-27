#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity979B4 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 unknown08(); // Slot 0x08.
};

typedef struct {
    s16 id;
    u8 pad2[0xe];
    s8 f10;
    u8 pad11[7];
} Msg;

typedef struct {
    s32 f0;
    s8 f4;
    u8 pad5;
    s16 f6;
    u8 pad8[20];
} Payload;

// 16 bit angle passed by value.
struct A16 {
    u16 v;
    A16(u16 a) {
        v = a;
    }
};

// Fixed point value class; passing it by value keeps the copies on the stack.
struct Fx {
    s32 v;
};

// Fixed point vector (the user constructor matters: a POD V3 drops the x copy).
struct V3 {
    Fx x, y, z;
    V3() {}
};

extern "C" u32 data_027e02a8;
extern "C" u8 data_0210794c[];

extern "C" void func_020370ec(void *msg);
extern "C" s16 func_020985d8(s32 x, s32 z); // fixed point arc-tangent
extern "C" void *func_0205e80c(u32 size, s32 heap, s32 align); // operator new
extern "C" void *func_02037128(void *self, void *owner, void *msg); // constructor
extern "C" void *func_020363f4(void *self, void *owner, s8 arg); // constructor
extern "C" void func_0202c1a8(void *list, void *node);
extern "C" void func_020b04f0(void *tag, s32 id, void *data, u32 size);

static inline s16 Atan(Fx x, Fx z) {
    Fx t = x; // FAKE: local copy of x; makes z's by-value copy store first, x in the lower slot
    return func_020985d8(t.v, z.v);
}

// Yaw from `from` to `to` on the x/z plane.
static inline s16 Yaw(const V3 &to, const V3 &from) {
    V3 d;
    d.z.v = to.z.v - from.z.v;
    d.y.v = to.y.v - from.y.v;
    d.x.v = to.x.v - from.x.v;
    d     = d; // FAKE: self-copy; keeps the z,y,x computation order but re-stores d as x,y,z
    return Atan(d.x, d.z);
}

static inline void SetAng(u8 *o, A16 a) {
    if (M2C_FIELD(o, u16 *, 0xca) != a.v) {
        M2C_FIELD(o, u16 *, 0xca) = a.v;
        M2C_FIELD(o, u8 *, 0xd0)  = 1;
    }
}

// Plain-name ROM calls for the original `new` + constructor sequences (the binary shows C++: operator new
// func_0205e80c followed by constructors that store base and derived vptrs).
extern "C" void func_020979b4(u8 *arg0, u8 *arg1) {
    Entity979B4 *o = (Entity979B4 *) arg1;
    if ((data_027e02a8 & 64) == 0) {
        Msg m;
        func_020370ec(&m);
        m.id  = 107;
        m.f10 = 1;
        SetAng(arg1, A16(Yaw(*(V3 *) (arg0 + 4), *(V3 *) (arg1 + 0xb0))));
        void *n = func_0205e80c(0x28, 1, 4);
        if (n != 0) {
            n = func_02037128(n, arg1, &m);
        }
        func_0202c1a8(arg1 + 0x5e0, n);
        n = func_0205e80c(0x10, 1, 4);
        if (n != 0) {
            n = func_020363f4(n, arg1, M2C_FIELD(arg0, s8 *, 0x3b));
        }
        func_0202c1a8(arg1 + 0x5e0, n);
    } else {
        Payload p;
        p.f0 = o->unknown08();
        p.f6 = Yaw(*(V3 *) (arg0 + 4), *(V3 *) (arg1 + 0xb0));
        p.f4 = M2C_FIELD(arg0, s8 *, 0x3b);
        func_020b04f0(data_0210794c, 16, &p, 255);
    }
}
