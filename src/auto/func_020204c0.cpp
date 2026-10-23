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

extern "C" void func_020202bc(void *);

extern "C" void func_020204c0(Entity *obj) {
    if (M2C_FIELD(obj, u16 *, 0x212) == 0x57) {
        if (M2C_FIELD(obj, u8 *, 0x1bc) != 6) {
            return;
        }
        obj->action(0x56, 0, 1, 0);
        M2C_FIELD(obj, u8 *, 0x1bc) = 7;
    } else {
        M2C_FIELD(obj, u8 *, 0x1bc) = 3;
        func_020202bc(obj);
    }
}
