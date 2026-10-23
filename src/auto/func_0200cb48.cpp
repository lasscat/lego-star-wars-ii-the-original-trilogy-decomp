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
extern "C" void func_02001990(Entity *, s32, s32);
extern "C" M2C_UNK data_020fcee8;
extern "C" void func_0200cc2c();
extern "C" void func_0200cc40();
extern "C" void func_0200ce88();

extern "C" Entity *func_0200cb48(Entity *self, M2C_UNK a1, s32 a2, M2C_UNK a3) {
    func_0200fe94(self, 0x8000, a1, a2, a3);
    // The derived class vtable stays in the ROM data, so the vptr is set by hand.
    M2C_FIELD(self, M2C_UNK **, 0) = (M2C_UNK *) &data_020fcee8;
    M2C_FIELD(self, u32 *, 0x1bc)  = 4;
    M2C_FIELD(self, u8 *, 0x1c0)   = 0;
    M2C_FIELD(self, u8 *, 0x1c1)   = 0;
    M2C_FIELD(self, u8 *, 0x1c2)   = 0;
    M2C_FIELD(self, u8 *, 0x1c6)   = 0;
    M2C_FIELD(self, u32 *, 0x1c8)  = 0;
    M2C_FIELD(self, u32 *, 0x1cc)  = 0;
    M2C_FIELD(self, u32 *, 0x1d0)  = 0;
    M2C_FIELD(self, u32 *, 0x1d4)  = 0;
    M2C_FIELD(self, u32 *, 0x1dc)  = 0;
    u32 flags                      = M2C_FIELD(self, u32 *, 0x8);
    flags |= 0x20;
    flags &= ~0x80;
    M2C_FIELD(self, u32 *, 0x8) = flags;
    func_02001990(self, 1, flags);
    M2C_FIELD(self, u32 *, 0x84)      = 0x19;
    M2C_FIELD(self, u16 *, 0x1c4)     = 0x78;
    M2C_FIELD(self, M2C_UNK **, 0x10) = (M2C_UNK *) &func_0200cc40;
    M2C_FIELD(self, M2C_UNK **, 0x14) = (M2C_UNK *) &func_0200cc2c;
    M2C_FIELD(self, M2C_UNK **, 0x18) = (M2C_UNK *) &func_0200ce88;
    self->action(0x8a, 1, 1, 0);
    return self;
}
