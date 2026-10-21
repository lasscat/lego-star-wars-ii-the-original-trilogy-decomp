#include "m2c.h"

// Fixed-point 12.12 position/velocity triple.
struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// The vtable address point of this class is 0x020fd1d0.
class Mover {
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
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void setPosition(Vec3 *); // Slot 0x38.
};

extern "C" void *func_0205e80c(u32 size, u32 flags, u32 align);
extern "C" void *func_0201cba8(void *obj, u32 flags, void *pos, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7, u32 a8);

extern "C" void *func_0205151c(void *self) {
    Vec3 a;
    Vec3 b;

    // The three components are read into temporaries first; the compiler keeps
    // them in registers and stores them back in ascending order.
    s32 t2 = M2C_FIELD(self, s16 *, 0x4) << 12;
    s32 t1 = M2C_FIELD(self, s16 *, 0x2) << 12;
    s32 t0 = M2C_FIELD(self, s16 *, 0x0) << 12;
    a.x    = t0;
    a.y    = t1;
    a.z    = t2;
    s32 u2 = M2C_FIELD(self, u16 *, 0xc) << 12;
    s32 u1 = M2C_FIELD(self, u16 *, 0xa) << 12;
    s32 u0 = M2C_FIELD(self, u16 *, 0x8) << 12;
    b.x    = u0;
    b.y    = u1;
    b.z    = u2;

    void *obj = func_0205e80c(0x1d8, 0, 4);
    if (obj != 0) {
        obj = func_0201cba8(obj, 0x800, &b, M2C_FIELD(self, u8 *, 0xe), M2C_FIELD(self, u8 *, 0x10),
                            M2C_FIELD(self, u8 *, 0x11), M2C_FIELD(self, u8 *, 0x12), M2C_FIELD(self, u8 *, 0x13), 0);
    }
    ((Mover *) obj)->setPosition(&a);
    return obj;
}
