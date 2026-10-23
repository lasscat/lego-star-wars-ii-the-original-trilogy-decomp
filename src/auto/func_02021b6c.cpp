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

extern "C" void func_02021b6c(Entity *obj, Entity **arg) {
    Entity *other = *arg;
    u16 h         = M2C_FIELD(other, u16 *, 0xc);
    if (h != 1 && h != 2) {
        return;
    }
    other->interact(obj, 10, 0);
    if (M2C_FIELD(obj, u16 *, 0x212) != 0x14e) {
        return;
    }
    M2C_FIELD(obj, u32 *, 0x8) |= 0x800;
    obj->action(0x56, 0, 1, 1);
    M2C_FIELD(obj, u8 *, 0x1bc) = 5;
}
