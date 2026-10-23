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

extern "C" M2C_UNK data_021027f8;
extern "C" M2C_UNK func_0205d060(M2C_UNK, M2C_UNK, M2C_UNK);
extern "C" M2C_UNK func_0203b574(M2C_UNK **, M2C_UNK);

extern "C" void func_0203b4f0(void *self) {
    if (func_0205d060((s32) &data_021027f8, 1, M2C_FIELD(self, s32 *, 0x18)) == 0 && M2C_FIELD(self, u8 *, 0xd) == 1) {
        func_0203b574((M2C_UNK **) self, 0);
        M2C_FIELD(self, u8 *, 0xd) = 2;
        M2C_FIELD(self, Entity **, 0x4)->action(0x19, 0, 1, 0);
        M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u32 *, 0x194) = 0;
        M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u32 *, 0x64)  = 0;
    }
}
