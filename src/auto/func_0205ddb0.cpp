#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Slot 0x1c takes the argument and a constant 0 and returns the next value.
class Actor5D {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual int unknown1c(int, int); // Slot 0x1c.
};

extern "C" int func_0205ddb0(Actor5D *obj, int arg) {
    u16 count = 0;
    while (arg != 0) {
        count = count + 1;
        // The original steps the argument back and forward by one 4-byte unit
        // around the call, each step guarded by its own null test.
        if (arg != 0) {
            arg -= 4;
        }
        if (arg != 0) {
            arg += 4;
        }
        arg = obj->unknown1c(arg, 0);
    }
    return count;
}
