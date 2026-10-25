#include "m2c.h"
extern "C" s32 FX_Div(s32, s32);
// Fixed-point scalar (20.12). Each by-value copy passed to the inline
// operator/ below is kept in its own stack slot (the scale slots at sp+0..0x10).
class Fixed {
public:
    s32 v;
    operator s32() const {
        return v;
    }
};
inline s32 operator/(s32 a, Fixed b) {
    return FX_Div(a, b);
}

class Vec3 {
public:
    s32 x;
    s32 y;
    s32 z;
    Vec3() {}
    Vec3(s32 ax, s32 ay, s32 az) :
        x(ax),
        y(ay),
        z(az) {}
    Vec3 operator+(const Vec3 &o) const {
        return Vec3(x + o.x, y + o.y, z + o.z);
    }
    static Vec3 FromZYX(s32 az, s32 ay, s32 ax) {
        return Vec3(ax, ay, az);
    }
    Vec3 operator/(const Fixed &s) const {
        // Arguments are evaluated right to left, so x is still divided first.
        return FromZYX(z / s, y / s, x / s); // FAKE: z-first order allocates the copies' slots as in the target
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

class Particle {
public:
    Vec3 pos;
    u8 pad0C[0x10];
    u16 id;
    u16 life;
};

class Node {
public:
    Particle *data;
    Node *next;
};

class List {
public:
    void *vtbl;
    Node *head;
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Emitter {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void killed(Particle *); // Slot 0xc.
    u8 pad04[0x34];
    List list;
};

struct Tables {
    u8 pad0[0x2972];
    u16 base[0x43];
    u8 pad1[0x2a08 - 0x2972 - 0x86];
    u32 bits[32];

    void Set(s32 n, u32 value) {
        if ((u32) n < 1024) {
            u32 w        = bits[n >> 5];
            bits[n >> 5] = (w & ~(1 << (n & 31))) | (value << (n & 31));
        }
    }
};

extern "C" Vec3 func_02095548(Emitter *, Particle *);
extern "C" void func_0205d4c8(List *, Node *);
extern "C" void func_0205e84c(void *);
extern "C" u8 func_020917b4(void *);
extern "C" Tables data_02104d90;
extern "C" u8 data_0210930c[];

extern "C" void func_020953b0(Emitter *self) {
    s32 n;
    Node *next;
    Vec3 d;
    u32 id;
    Node *node;
    Particle *p;

    node        = self->list.head;
    p           = node->data;
    Vec3 target = func_02095548(self, p);
    do {
        d.z       = target.z - p->pos.z;
        d.x       = target.x - p->pos.x;
        d.y       = target.y - p->pos.y;
        s32 scale = p->life << 12;
        p->pos    = p->pos + d / reinterpret_cast<const Fixed &>(scale); // FAKE: orders the scale store after the loads
        next      = node->next;
        p->life--;
        if (p->life == 0) {
            func_0205d4c8(&self->list, node);
            self->killed(p);
            id = p->id;
            if (id != 0xFFFF) {
                n = data_02104d90.base[func_020917b4(data_0210930c)];
                n += id;
                data_02104d90.Set(n, 1);
            }
            if (p != 0) {
                func_0205e84c(p);
            }
            p = 0;
        }
        if (next != 0) {
            p = next->data;
        }
        node = next;
    } while (node != 0);
}
