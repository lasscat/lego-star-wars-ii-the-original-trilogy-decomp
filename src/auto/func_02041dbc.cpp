#include "m2c.h"

// Fixed-point vector with a self-checking assignment.
struct Vec3 {
    s32 x, y, z;
    Vec3(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
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

struct Ctrl;

// Declaration-only parent class: slot 9 is the observed call.
class Parent {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void m(s32, s32, s32, s32);

    u8 pad4[4];
    u32 flags;     // 0x8
    u8 padc[0xa4]; // 0xc
    s32 px, py, pz; // 0xb0
    u8 padbc[0x690 - 0xbc];
    Ctrl *ctrl; // 0x690
};

struct Ptr {
    void *p;
};

struct Node {
    s32 f0;
    Ctrl *owner;
    Parent *parent;
    Vec3 pos;
    u32 pad18;
    Ptr arr[2];
    Vec3 vel;
    u8 pad30[8];

    void Init(Ctrl *o);
};

struct Ctrl {
    void *vptr;
    Parent *parent;
    u32 f8;
    u8 c;
    u8 d;
    Node *node;
};

extern "C" u32 data_020fdbc4;
extern "C" u32 data_020fe21c;
extern "C" s32 data_020fe208;
extern "C" void *func_0205e824(u32 size);
extern "C" void func_020e46bc(void *, s32, s32, void *, void *);
extern "C" void func_020402d0(void *);
extern "C" void func_02040078(void *);
extern "C" void func_02004acc(void *);

inline void Node::Init(Ctrl *o) {
    owner = o;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    func_020e46bc(arr, 2, 4, (void *) func_020402d0, (void *) func_02040078);
    vel.x = 0;
    vel.y = 0;
    vel.z = 0;
}

// Plain-name constructor (binary shows C++: two vptr stores, then the allocator veneer and an inlined node
// constructor). The vptr stores and the ctor/dtor callbacks of the 2-element Ptr array
// (__construct_array) are spelled with plain data_/func_ names so that no vtable or .ctor/.init is emitted.
extern "C" Ctrl *func_02041dbc(Ctrl *self, Parent *parent) {
    self->vptr   = &data_020fdbc4;
    self->parent = parent;
    self->c      = 0;
    self->d      = 0;
    self->vptr   = &data_020fe21c;
    Node *n      = (Node *) func_0205e824(0x38);
    if (n != 0) {
        n->Init(self);
        n->parent = n->owner->parent;
        n->parent->flags &= ~0x20;
        func_02004acc(n->parent);
        n->f0 = 0;
        Vec3 v(n->parent->px, n->parent->py + data_020fe208, n->parent->pz);
        n->pos = v;
        n->parent->m(189, 1, 1, 0);
    }
    self->node         = n;
    self->parent->ctrl = self;
    return self;
}
