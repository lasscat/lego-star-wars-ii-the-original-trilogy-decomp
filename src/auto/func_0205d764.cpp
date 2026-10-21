#include "m2c.h"

// The vtable of this class lives in the ROM data; only its address point is
// referenced here (data_020fe5dc = slot 0x00 = func_0205d72c).
extern "C" s32 data_020fe5dc;

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// This is the class whose vtable address point is data_020fe5dc
// (slots 0x00..0x2c); only the slots actually dispatched are named.
class Entity764 {
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
    virtual void unknown28(void *);
    virtual void unknown2c();
};

extern "C" void *func_0205df2c(void **);
extern "C" void *func_0205d3f4(void *);
extern "C" void func_0205e84c(void *);

extern "C" void *func_0205d764(Entity764 *obj) {
    M2C_FIELD(obj, void **, 0) = (void *) &data_020fe5dc;
    obj->unknown18();
    func_0205df2c((void **) ((u8 *) obj + 0x14));
    func_0205d3f4(obj);
    func_0205e84c(obj);
    return obj;
}
