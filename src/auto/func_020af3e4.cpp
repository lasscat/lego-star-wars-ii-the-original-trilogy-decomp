#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Slot 0x04 returns a pointer to another object of the same hierarchy.
class Owner {
public:
    virtual void unknown00();
    virtual Owner *unknown04(); // Slot 0x04.
};

extern "C" void func_020af3e4(Owner *self) {
    Owner *o                              = self->unknown04();
    M2C_FIELD(o, u8 *, 0x6e)              = M2C_FIELD(o, u8 *, 0x6e) + 1;
    u32 i                                 = M2C_FIELD(self, u8 *, 0x6ae) & 7;
    M2C_FIELD(self, u32 *, 0x6b8 + i * 8) = M2C_FIELD(self, u32 *, 0x6a0);
    M2C_FIELD(self, u16 *, 0x6b4 + i * 8) = M2C_FIELD(self, u16 *, 0x6a8);
}
