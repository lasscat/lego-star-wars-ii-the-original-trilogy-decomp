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

extern "C" void func_0209f948(void *a, u32 b);

extern "C" void func_0201e6dc(Entity *self, s32 a) {
    if (a != 3) {
        return;
    }
    M2C_FIELD(self, u8 *, 0x1bc) = 3;
    self->action(0x58, 0, 1, 0);
    u32 v = M2C_FIELD(self, u32 *, 0x148);
    v     = v ? (u32) M2C_FIELD(M2C_FIELD(v, u32 *, 8), u16 *, 4) << 12 : 0;
    // The original keeps the range value in a stack slot next to the call.
    volatile u32 range = v - 0x1000;
    func_0209f948((u8 *) self + 0xd4, v - 0x1000);
}
