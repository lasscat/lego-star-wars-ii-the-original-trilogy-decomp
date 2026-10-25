#include "m2c.h"

// Fixed-point 12.12 vector.
struct V3 {
    s32 x, y, z;

    // FAKE: zeroing default constructor = dead stores; they make the compiler load `mov r1, #0` ahead
    // of the allocation call (target order r1, r0, r2) and are then removed. Not used by the original.
    V3() {
        x = 0;
        y = 0;
        z = 0;
    }
    V3(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
    }
    void Set(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
    }
};

struct S16V3 {
    s16 x, y, z;
};

struct R3 {
    u16 x, y, z;
    R3() {}
    R3(u16 ax, u16 ay, u16 az) {
        x = ax;
        y = ay;
        z = az;
    }
};

struct Mtx {
    u8 d[0x48];
};

struct Obj {
    u8 pad[8];
    u32 flags;
    u8 rest[0xd4 - 12];
};

// Plain-name ROM functions; the C++ new/constructor sequence is spelled out as the calls it compiles to.
extern "C" void *func_0205e80c(u32 size, s32 heap, s32 align);                                 // operator new
extern "C" Mtx *func_020accac(Mtx *self, const V3 *pos, const R3 *rot, const V3 *scale);       // Mtx ctor
extern "C" Obj *func_020179b4(Obj *self, s32 a, s32 b, const Mtx *m);                          // Obj ctor

extern "C" Obj *func_02051430(S16V3 *arg0) {
    s32 z = arg0->z << 12;
    s32 y = arg0->y << 12;
    s32 x = arg0->x << 12;
    V3 pos;
    pos.Set(x, y, z);
    Obj *obj = (Obj *) func_0205e80c(0xd4, 0, 4);
    if (obj != 0) {
        Mtx m;
        V3 scale(0x1000, 0x1000, 0x1000);
        R3 rot(0, 0, 0);
        func_020accac(&m, &pos, &rot, &scale);
        obj = func_020179b4(obj, 0x200, 0, &m);
    }
    obj->flags |= 0x200000;
    return obj;
}
