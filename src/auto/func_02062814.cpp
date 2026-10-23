#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Same Actor62814 interface as src/auto/func_02062868.cpp (element stride 0x38).
// Slots 0x08 and 0x10 receive the second argument.
class Actor62814 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(int); // Slot 0x08.
    virtual void unknown0c(int); // Slot 0x0c.
    virtual void unknown10(int); // Slot 0x10.
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual Actor62814 *unknown34(Actor62814 *);
    u8 field04[52]; // 0x04..0x37; the element stride is 0x38.
};

extern "C" void func_02062814(Actor62814 *entries, int arg, int selector, int index) {
    int i = 0;
    if (index >= 2) {
        i = 1;
    }
    switch (selector) {
        case 0:
            entries[i].unknown08(arg);
            break;
        case 1:
            entries[i].unknown10(arg);
            break;
    }
}
