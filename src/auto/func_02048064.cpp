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

extern "C" u32 func_02062ae4(s32);

extern "C" void func_02048064(void *self) {
    // The entity pointer is re-read from self after each store, as in the original.
    M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u32 *, 0x8) |= 0x200;
    u16 state = M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u16 *, 0x182);
    if (state >= 0x21 && state <= 0x26) {
        M2C_FIELD(self, Entity **, 0x4)->action(state + 0x15, 0, 1, 0);
    } else {
        M2C_FIELD(self, Entity **, 0x4)->action(func_02062ae4(5) + 0x3c, 0, 1, 0);
    }
}
