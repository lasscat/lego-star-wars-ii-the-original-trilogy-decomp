#include "m2c.h"

// The vtable of this class lives in the ROM data; only its address point is
// referenced here (data_020fe614 = slot 0x00 = func_0205d39c).
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

// The derived class whose vtable address point is data_020fe5dc
// (slot 0x00 = func_0205d72c, slot 0x18 = func_0205d7a4). It adds no virtual
// of its own: the base sub-object sits at offset 0x00.
class Entity5D72c : public Entity5D {};

// The vtable of the derived class lives in the ROM data.
extern "C" s32 data_020fe5dc;

extern "C" void **func_0205df2c(void **obj);
extern "C" void *func_0205d3f4(Entity5D *obj);

extern "C" void *func_0205d72c(Entity5D72c *obj) {
    M2C_FIELD(obj, void **, 0) = (void *) &data_020fe5dc;
    obj->unknown18();
    func_0205df2c((void **) ((s8 *) obj + 0x14));
    func_0205d3f4(obj);
    return obj;
}
