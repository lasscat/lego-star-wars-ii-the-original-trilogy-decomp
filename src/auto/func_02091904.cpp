#include "m2c.h"

struct Pos {
    u8 pad0[0x14];
    s32 x, y, z; // 0x14
};

// Declaration-only interface: slot 1 is the observed release call.
class Entity {
public:
    virtual void v0();
    virtual void release();

    u8 pad4[0x1c];
    Pos *pos; // 0x20
};

struct Owner {
    u8 pad0[0x384];
    s32 tag; // 0x384
};

struct Actor {
    u8 pad0[0x20];
    Pos *pos; // 0x20
    u8 pad24[0x8c - 0x24];
    u8 extra[4]; // 0x8c
    u8 pad90[0x190 - 0x90];
    u8 *info; // 0x190
};

struct Game {
    u8 pad0[0x4c];
    Actor *actors[7]; // 0x4c
    Owner *owner; // 0x68
};

struct Entry {
    u16 id;
    u8 rest[22];
};

struct V3 {
    s32 x, y, z;
};

struct Box {
    V3 a, b;
};

struct Row {
    u8 pad0[4];
    u16 key; // 4
    u16 pad6;
};

inline void Release(Entity *e) {
    if (e != 0) {
        e->release();
    }
}

extern "C" Entry data_020ef57c[];
extern "C" Row data_020eb7b8[];
extern "C" s32 data_027e02a4;
extern "C" s32 data_020ff9b4;
extern "C" Row *func_02010c0c(Row *r, s32 a);
// C++ exception (docs/exceptions.md, constructors/operator new): the binary shows the game's operator new
// (func_0205e80c) followed by the vptr constructor func_0200ff50 behind the null check, and a virtual
// release call (vtable slot 1) on the result at every exit. Spelled with plain extern "C" names; Entity has
// declaration-only virtuals, so no vtable/RTTI/.ctor/.init/.data is emitted (.text only).
extern "C" void *func_0205e80c(u32 size, s32 heap, s32 align); // operator new
extern "C" Entity *func_0200ff50(Entity *self, s32 a, s32 id, s32 b, void *extra); // Entity ctor
extern "C" s32 func_01ffa188(Actor *a, Pos *p, s32 *d);
extern "C" Box *func_0204c5fc(Box *out, const V3 *a, const V3 *b);
extern "C" s32 func_0204c8a8(s32 a, const Box &v);

extern "C" s32 func_02091904(Game *self, s32 idx, s32 kind) {
    Actor *a = self->actors[idx];
    Entity *e;
    s32 id   = data_020ef57c[kind].id;
    Row *row = func_02010c0c(&data_020eb7b8[id], 0);
    if (row->key == *(u16 *) (a->info + 0x28)) {
        return 1;
    }
    e = (Entity *) func_0205e80c(0x1bc, 0, 4);
    if (e != 0) {
        e = func_0200ff50(e, 1, id, data_027e02a4, a->extra);
    }
    Pos *p = a->pos;
    Pos *q = e->pos;
    if (q->x <= p->x && q->y <= p->y && q->z <= p->z) {
        Release(e);
        return 1;
    }
    if (func_01ffa188(a, q, &data_020ff9b4)) {
        Release(e);
        return 0;
    }
    Box box;
    func_0204c5fc(&box, (V3 *) ((u8 *) q + 4), (V3 *) ((u8 *) q + 20));
    Release(e);
    return func_0204c8a8(self->owner->tag, box) == 0;
}
