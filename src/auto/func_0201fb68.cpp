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

// Base constructor: the caller only passes the object and the type id.
extern "C" void func_02011384(Entity *self, s32 type);
extern "C" M2C_UNK data_020fd4d0;

extern "C" Entity *func_0201fb68(Entity *self, s32 type) {
    func_02011384(self, type);
    // The derived class vtable stays in the ROM data, so the vptr is set by hand.
    M2C_FIELD(self, M2C_UNK **, 0) = (M2C_UNK *) &data_020fd4d0;
    if (type == 0xb1) {
        self->action(0, 1, 1, 0);
        self->action(0x8a, 0, 1, 0);
        self->action(0x78, 0, 1, 0);
        M2C_FIELD(self, u8 *, 0x1bc) = 1;
    }
    return self;
}
