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

extern "C" void func_0201ee44(Entity *obj) {
    u8 state = M2C_FIELD(obj, u8 *, 0x1bc);
    if (state != 0 && state != 4) {
        return;
    }
    M2C_FIELD(obj, u8 *, 0x1bc) = 3;
    M2C_FIELD(obj, u32 *, 0x8)  = (M2C_FIELD(obj, u32 *, 0x8) | 1) & ~0x200000;
    if (M2C_FIELD(obj, u8 *, 0x216) != 0) {
        M2C_FIELD(obj, u8 *, 0x217) = 0;
        obj->action(0x5a, 0, 1, 0);
    } else {
        obj->action(0x56, 0, 1, 1);
    }
}
