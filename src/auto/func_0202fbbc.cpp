#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity2FBBC {
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
    virtual void unknown28();
    virtual void interact(Entity2FBBC *, int, int); // Slot 0x2c.
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual s32 unknown44(); // Slot 0x44.
};

// A three word position value with the assignment the original performs.
class Vec32FBBC {
public:
    s32 x, y, z;

    Vec32FBBC &operator=(const Vec32FBBC &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
};

extern "C" u8 data_020ef582[];

extern "C" void func_02010c6c(void *a0, s32 a1, s32 a2, s32 a3, u8 a4, void *a5, s32 a6, s32 a7);

#define ENT(obj) M2C_FIELD(obj, void **, 4)

extern "C" void func_0202fbbc(void *obj, s32 a1, s32 a2) {
    s32 code;
    if (a2 == -1) {
        code = data_020ef582[M2C_FIELD(ENT(obj), u8 *, 0x6bb) * 24];
    } else {
        code = a2;
    }
    if (data_020ef582[M2C_FIELD(ENT(obj), u8 *, 0x6bb) * 24] == 2) {
        code = 2 + (M2C_FIELD(obj, u8 *, 0x1e) & 1 ? 1 : 0);
    }

    M2C_FIELD(obj, u8 *, 0x1e) ^= 1;

    u32 *ent = (u32 *) ENT(obj);
    u32 *p   = M2C_FIELD(ent, u32 **, 0x30);
    Vec32FBBC v;
    v.x = M2C_FIELD(ent, u32 *, 0xb0);
    v.y = M2C_FIELD(ent, u32 *, 0xb4);
    v.z = M2C_FIELD(ent, u32 *, 0xb8);
    if (p != 0) {
        v = *(Vec32FBBC *) ((u8 *) p + 4);
    }

    Entity2FBBC *e = (Entity2FBBC *) ENT(obj);
    s32 res        = e->unknown44();
    func_02010c6c(ENT(obj), code, 0, res, M2C_FIELD(e, u8 *, 0x5da), &v, a1, 0);
}
