#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Slot 0x04 returns a pointer to another object of the same hierarchy.
class Owner {
public:
    virtual void unknown00();
    virtual Owner *unknown04(); // Slot 0x04.
};

extern "C" void func_020af864(Owner *self, u32 val) {
    M2C_FIELD(self, u8 *, 0x6f4)             = val;
    M2C_FIELD(self->unknown04(), u8 *, 0x6d) = val;
    M2C_FIELD(self->unknown04(), u8 *, 0x6e) = 0;
}
