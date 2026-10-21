#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

extern "C" void func_02029428(Entity *);

extern "C" void func_0202817c(Entity *a, Entity *b) {
    if (a == 0 || b == 0) {
        return;
    }
    func_02029428(b);
    b->action(0x29, 0, 1, 0);
    a->action(0xf, 0, 1, 0);
}
