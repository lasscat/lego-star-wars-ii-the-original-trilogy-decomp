#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// The class is the one whose vtable address point is data_020fe614
// (slots 0x00..0x2c); only the slots actually dispatched here are named.
class Entity5D {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28(void *); // Slot 0x28.
};

extern "C" void func_0205d4c8(Entity5D *obj, void *arg) {
    obj->unknown28(arg);
    M2C_FIELD(obj, u16 *, 0xc) -= 1;
}
