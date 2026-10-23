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
extern "C" M2C_UNK data_020fd330;
extern "C" void func_0201e67c(void *, void **);
extern "C" void func_0201e5d8(Entity *, Entity **);

extern "C" Entity *func_0201e2ec(Entity *self, u32 arg) {
    func_02011384(self, arg);
    M2C_FIELD(self, u32 *, 0x0) = (u32) &data_020fd330;
    if (arg == 0x86 || arg == 0x146) {
        M2C_FIELD(self, u8 *, 0x1bc) = 0;
        M2C_FIELD(self, u8 *, 0x216) = 1;
    } else {
        M2C_FIELD(self, u8 *, 0x1bc) = 1;
        M2C_FIELD(self, u8 *, 0x216) = 0;
    }
    M2C_FIELD(self, u16 *, 0x1be) = 0x96;
    M2C_FIELD(self, u32 *, 0x84)  = 0x16;
    M2C_FIELD(self, u32 *, 0x14)  = (u32) &func_0201e67c;
    M2C_FIELD(self, u32 *, 0x18)  = (u32) &func_0201e5d8;
    self->action(0, 0, 1, 0);
    if (arg == 0x9a) {
        M2C_FIELD(self, u16 *, 0x1a8) |= 0x1000;
    }
    return self;
}
