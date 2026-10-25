#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
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

// Fixed-point 12.12 vector with an inlined self-checked copy assignment.
struct V3 {
    s32 x, y, z;
    V3(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
    }
    bool operator!=(const V3 &o) const {
        // Short-circuit chain accumulated into a flag (the form that compiles to the original cmp/cmpeq chain).
        bool r = false;
        if (x != o.x || y != o.y || z != o.z) {
            r = true;
        }
        return r;
    }
    V3 &operator=(const V3 &o) {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }
        return *this;
    }
};

struct ModelInfo {
    u8 pad[4];
    u16 h4;
};

struct ModelRef {
    u8 pad[8];
    ModelInfo *info;
};

struct Pair {
    u16 a;
    u16 b;
};

class Actor : public Entity {
public:
    u8 pad04[0xbc - 4];
    V3 scale;            // 0xbc
    u8 padc8[0xd1 - 0xc8];
    u8 dirty;            // 0xd1
    u8 padd2[0x148 - 0xd2];
    ModelRef *model;     // 0x148
    u8 pad14c[0x1bc - 0x14c];
    u16 h1bc;
    u8 b1be;
    u8 b1bf;
    void SetScale(const V3 &v) {
        if (scale != v) {
            scale = v;
            dirty = 1;
        }
    }
};

extern "C" void *func_0200fe94(void *, M2C_UNK, s32, M2C_UNK, M2C_UNK);
extern "C" void func_020b95bc(s32, void *);
extern "C" M2C_UNK data_020fcd30;
// Read-only type table (u16 pair per type). const matters: the outgoing stack argument store may then be
// scheduled after the table load, as in the original prologue.
extern "C" const Pair data_020e5cc0[];

extern "C" Actor *func_0200af90(Actor *self, M2C_UNK a1, s32 idx, s32 scale, M2C_UNK a4, M2C_UNK a5) {
    func_0200fe94(self, a1, data_020e5cc0[idx].a, a4, a5);
    // The derived class vtable stays in the ROM data, so the vptr is set by hand.
    M2C_FIELD(self, M2C_UNK **, 0) = (M2C_UNK *) &data_020fcd30;
    self->b1be                     = 0;
    self->b1bf                     = idx;
    self->SetScale(V3(scale << 12, scale << 12, scale << 12));
    self->action(0, 0, 0, 0);
    if (idx == 7) {
        self->action(138, 0, 0, 0);
    }
    s32 v      = self->model != 0 ? (s32) (self->model->info->h4 << 12) : 0;
    self->h1bc = v >> 12;
    u16 b      = data_020e5cc0[idx].b;
    if (b != 201) {
        func_020b95bc(b, self);
    }
    return self;
}
