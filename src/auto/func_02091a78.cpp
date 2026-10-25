#include "m2c.h"

struct Vec3 {
    s32 x, y, z;
    Vec3(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
    }
    bool operator!=(const Vec3 &o) const {
        if (x != o.x || y != o.y || z != o.z) {
            return true;
        }
        return false;
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

struct Node {
    u8 pad0[0x24];
    Vec3 pos;
    u8 pad30[0x45 - 0x30];
    u8 dirty;
    u8 pad46[0x384 - 0x46];
    u32 flags;
    u8 pad388[0x3a0 - 0x388];
};

// C++ exception (docs/exceptions.md, constructors/operator new): the binary shows the game's operator new
// (func_0205e80c) followed by a constructor call (func_020bbfe8) behind the null check. Spelled out with
// plain extern "C" names; Node has no virtuals, so no vtable/RTTI/.ctor/.init/.data is emitted (.text only).
// Plain-name ROM functions; the C++ new/constructor sequence is spelled out as the calls it compiles to.
extern "C" void *func_0205e80c(u32 size, s32 heap, s32 align);  // operator new
extern "C" Node *func_020bbfe8(Node *self);                      // Node ctor
extern "C" s32 func_0205ab44(s32 id);
extern "C" s32 func_0205ab58(s32 id);
extern "C" void func_020bbeb0(Node *self, s32 a);
extern "C" void func_020bbf78(Node *self, s32 id, s32 b, s32 c);
extern "C" void func_020bc4cc(Node *self, s32 a);

extern "C" void func_02091a78(void *arg0, const Vec3 *p) {
    Node *n = (Node *) func_0205e80c(0x3a0, 3, 4);
    if (n != 0) {  // null check of operator new's result
        n = func_020bbfe8(n);
    }
    func_020bbeb0(n, func_0205ab44(0x5a9));
    func_020bbf78(n, 0x5aa, func_0205ab58(0x5aa), 0);
    Vec3 v(p->x, p->y + 0x4000, p->z);
    if (n->pos != v) {
        n->pos   = v;
        n->dirty = 1;
    }
    func_020bc4cc(n, 1);
    n->flags |= 0x80000000;
}
