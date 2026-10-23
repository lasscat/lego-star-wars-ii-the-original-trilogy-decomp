#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// This is the class whose vtable address point is data_020fe65c
// (slots 0x00..0x38); only the slots actually dispatched are named.
class Entity83C {
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
    virtual void unknown2c();
    virtual void unknown30();
    virtual void *unknown34(void *); // Slot 0x34.
    virtual void unknown38();
};

extern "C" void func_0205d8e0(Entity83C *obj, void *arg) {
    void *q = obj->unknown34(arg);
    if (q != 0) {
        q = (void *) ((u8 *) q + 4);
    }
    if (q == 0) {
        return;
    }
    obj->unknown28(q);
    M2C_FIELD(obj, u16 *, 0xc) -= 1;
}
