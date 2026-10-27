#include "m2c.h"

// Partial interface: unknown virtuals keep their observed vtable slots.
class Actor0200cef4 {
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
    virtual void unknown24(s32, s32, s32, s32); // Slot 0x24.
};

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

extern "C" u8 data_02106d90[];
extern "C" void func_0209d0e0(s32 arg0, s32 arg1);
extern "C" void func_020b9584(s32 arg0, void *arg1);
extern "C" void *func_0205e80c(s32, s32, s32);
extern "C" void *func_020bbfe8(void *);
extern "C" s32 func_0205ab44(s32);
extern "C" s32 func_0205ab58(s32);
extern "C" void func_020bbeb0(void *arg0, s32 arg1);
extern "C" void func_020bbf78(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" void func_020bc4cc(void *arg0, s32 arg1);

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    if (!(a->x == b->x && a->y == b->y && a->z == b->z)) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

enum {
    SPAWNED_OBJECT_SIZE = 0x3a0,
    HIGH_BIT            = 0x80000000,
};

// Allocates one 0x3a0-byte object (same allocator call shape as func_020b9584)
// and runs its initialiser when the allocation succeeded.
static inline u8 *make_obj(void) {
    u8 *o = (u8 *) func_0205e80c(SPAWNED_OBJECT_SIZE, 3, 4);
    if (o != NULL) {
        o = (u8 *) func_020bbfe8(o);
    }
    return o;
}

// Moves a spawned object to pos (flagging +0x45 only when the position
// changed), runs one func_020bc4cc pass and sets the top bit of +0x384.
static inline void place(u8 *o, const Vec3 *pos) {
    if (vec_ne((Vec3 *) (o + 0x24), pos)) {
        vec_set((Vec3 *) (o + 0x24), pos);
        o[0x45] = 1;
    }
    func_020bc4cc(o, 1);
    *(u32 *) (o + 0x384) |= HIGH_BIT;
}

// One-shot trigger: does nothing once +0x1c1 is set. Otherwise bumps the
// counter selected by the low byte of +0x1bc in the global object at
// data_02106d90+0xad0 (when +0x1c0 is set), calls virtual slot 0x24, marks
// itself done, then spawns three objects, binds each to a pair of resource
// ids and places all three at the position held at +0xb0.
extern "C" void func_0200cef4(u8 *self) {
    Vec3 pos;
    u8 *a;
    u8 *b;
    u8 *c;
    s32 counters;
    Vec3 *src;

    if (self[0x1c1] != 0) {
        return;
    }
    counters = *(s32 *) (*(u8 **) (data_02106d90 + 0xad0) + 0x10);
    if (counters != 0 && self[0x1c0] != 0) {
        func_0209d0e0(counters, *(u32 *) (self + 0x1bc) & 0xff);
    }
    ((Actor0200cef4 *) self)->unknown24(0x35, 0, 1, 0);
    self[0x1c1] = 1;
    self[0x1c6] = 2;
    func_020b9584(0x43, self + 0xb0);
    src   = (Vec3 *) (self + 0xb0);
    pos.x = src->x;
    pos.y = src->y;
    pos.z = src->z;
    a     = make_obj();
    b     = make_obj();
    c     = make_obj();
    func_020bbeb0(a, func_0205ab44(0x8a4));
    func_020bbf78(a, 0x8a8, func_0205ab58(0x8a8), 0);
    func_020bbeb0(b, func_0205ab44(0x8b8));
    func_020bbf78(b, 0x8a9, func_0205ab58(0x8a9), 0);
    func_020bbeb0(c, func_0205ab44(0x8b5));
    func_020bbf78(c, 0x8b3, func_0205ab58(0x8b3), 0);
    place(a, &pos);
    place(b, &pos);
    place(c, &pos);
}
