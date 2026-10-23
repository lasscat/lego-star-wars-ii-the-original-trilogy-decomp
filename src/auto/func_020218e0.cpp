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
    virtual void unknown28();
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

extern "C" void func_020140f8(Entity *);
extern "C" void func_02016664(Entity *);

extern "C" void func_020218e0(Entity *obj) {
    if (M2C_FIELD(obj, u8 *, 0x1bc) != 0) {
        return;
    }
    M2C_FIELD(obj, u8 *, 0x1d8) = M2C_FIELD(obj, s8 *, 0x1d8) + 1;
    if (M2C_FIELD(obj, s8 *, 0x1d8) < M2C_FIELD(obj, u8 *, 0x1dc)) {
        return;
    }
    M2C_FIELD(obj, u8 *, 0x1bc) = 1;
    obj->action(0x56, 0, 1, 0);
    u32 t = M2C_FIELD(obj, u16 *, 0x212);
    if (t == 0xa9 || t == 0x8d || t == 0x141 || t == 0xfc) {
        obj->action(0x8b, 1, 1, 0);
    }
    u32 t2 = M2C_FIELD(obj, u16 *, 0x212);
    if (t2 == 0x137 || t2 == 0xfa || t2 == 0xfb) {
        func_020140f8(obj);
        func_02016664(obj);
        M2C_FIELD(obj, u32 *, 8) |= 2;
    }
}
