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

extern "C" void *func_0200fe94(void *, M2C_UNK, s32, M2C_UNK, s32);
extern "C" M2C_UNK data_020fce90;

extern "C" Entity *func_0200ca7c(Entity *self, M2C_UNK a1, s32 a2, M2C_UNK a3) {
    func_0200fe94(self, 0x8000, a1, a2, a3);
    // The derived class vtable stays in the ROM data, so the vptr is set by hand.
    M2C_FIELD(self, M2C_UNK **, 0) = (M2C_UNK *) &data_020fce90;
    self->action(0x35, 0, 1, 0);
    return self;
}
