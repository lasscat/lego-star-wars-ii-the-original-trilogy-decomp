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

extern "C" u32 func_0202cb68(void *);
extern "C" u32 func_0202cb7c(void *);

extern "C" void func_020329a4(void *self) {
    M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u32 *, 0x8) |= 0x200;
    M2C_FIELD(self, Entity **, 0x4)->action(0, 1, 0, 0);
    if (M2C_FIELD(self, u8 *, 0x1c) == 0) {
        return;
    }
    M2C_FIELD(self, u32 *, 0x10) = func_0202cb68((u8 *) M2C_FIELD(self, Entity **, 0x4) + 0x5e0);
    M2C_FIELD(self, u32 *, 0x14) = func_0202cb7c((u8 *) M2C_FIELD(self, Entity **, 0x4) + 0x5e0);
}
