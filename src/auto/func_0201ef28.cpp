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

extern "C" void func_02011384(Entity *self, int arg);
extern "C" u32 data_020fd400[];

extern "C" Entity *func_0201ef28(Entity *self, u32 arg) {
    func_02011384(self, arg);
    M2C_FIELD(self, u32 *, 0x0) = (u32) data_020fd400;
    if (arg == 0xb || arg == 0xc || arg == 0x24 || arg == 0xd || arg == 0x25 || arg - 0x189 <= 2) {
        self->action(0x8a, 1, 1, 0);
        M2C_FIELD(self, u8 *, 0x1bc) = 1;
    }
    if (arg == 0xb || arg == 0xc || arg == 0xd || arg - 0x189 <= 2) {
        M2C_FIELD(self, u32 *, 0x8) &= ~0x1000000;
    }
    M2C_FIELD(self, u32 *, 0x218) = 0x190;
    M2C_FIELD(self, u32 *, 0x21c) = 0;
    return self;
}
