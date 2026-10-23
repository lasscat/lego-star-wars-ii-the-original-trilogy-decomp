#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Declaration is identical to the pilot class in src/auto/func_02020a9c.cpp,
// so the coordinator can keep both translation units on one shared interface.
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

extern "C" void func_02026364(Entity *obj, Entity **arg) {
    Entity *other = *arg;
    switch (M2C_FIELD(other, u16 *, 0xc)) {
        case 1:
        case 2:
            if (M2C_FIELD(obj, u8 *, 0x217) != 0) {
                other->interact(obj, 10, 0);
            }
            break;
    }
}
