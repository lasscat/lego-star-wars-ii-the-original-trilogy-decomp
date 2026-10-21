#include "m2c.h"

// The vtable of this class lives in the ROM data; only its address point is
// referenced here (data_020fe614 = slot 0x00 = func_0205d39c).
extern "C" s32 data_020fe614;

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
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

// Teardown helper called on the object.
extern "C" void func_0205e84c(void *);

extern "C" void *func_0205d3c4(Entity5D *obj) {
    M2C_FIELD(obj, void **, 0) = (void *) &data_020fe614;
    obj->unknown18();
    func_0205e84c(obj);
    return obj;
}
