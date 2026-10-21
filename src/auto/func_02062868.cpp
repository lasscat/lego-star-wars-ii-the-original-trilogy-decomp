#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Actor {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(int); // Slot 0x0c.
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual Actor *unknown34(Actor *);
    u8 field04[52]; // 0x04..0x37; the element stride is 0x38.
};

extern "C" void func_02062868(Actor *entries, int arg, int index) {
    int i = 0;
    if (index >= 2) {
        i = 1;
    }
    entries[i].unknown0c(arg);
}
