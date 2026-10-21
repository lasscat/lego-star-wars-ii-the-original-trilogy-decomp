#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class GapObject {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
};

extern "C" void func_0201b614(GapObject *obj, int arg);

extern "C" void func_0201b1fc(GapObject *obj) {
    func_0201b614(obj, 1);
    obj->unknown18();
    if (M2C_FIELD(obj, u8 *, 0x45) & 0x10) {
        M2C_FIELD(obj, u32 *, 0x10) |= 0x10000000;
        obj->unknown18();
        M2C_FIELD(obj, u32 *, 0x10) &= ~0x10000000;
    }
}
