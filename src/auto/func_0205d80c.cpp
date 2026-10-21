#include "m2c.h"

// The vtable of this class lives in the ROM data; only its address point is
// referenced here (data_020fe65c = slot 0x00 = func_0205d80c).
extern "C" s32 data_020fe65c;

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

extern "C" void *func_0205d3f4(void *);

extern "C" void *func_0205d80c(Entity83C *obj) {
    M2C_FIELD(obj, void **, 0) = (void *) &data_020fe65c;
    obj->unknown18();
    func_0205d3f4(obj);
    return obj;
}
