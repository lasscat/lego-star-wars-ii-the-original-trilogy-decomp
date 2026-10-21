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

extern "C" void func_0200cc40(Entity *, Entity **);

extern "C" void func_0200ce88(Entity *self, Entity **arg1) {
    if (M2C_FIELD(self, u8 *, 0x1c1) == 0) {
        func_0200cc40(self, arg1);
        return;
    }
    Entity *obj = *arg1;
    u16 state   = M2C_FIELD(obj, u16 *, 0xc);
    // The state 1 and state 2 paths both dispatch slot 0x2c. The state 1 path
    // is the else arm of the first test, which is how the original block
    // layout puts it after the state 2 path.
    if (state != 1) {
        if (state == 2) {
            obj->interact(self, 2, 9);
        }
    } else {
        obj->interact(self, 2, 9);
    }
}
