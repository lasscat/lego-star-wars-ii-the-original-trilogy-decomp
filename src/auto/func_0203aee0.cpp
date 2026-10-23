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

extern "C" void func_0203aee0(void *self) {
    u8 *p = *(u8 **) ((s8 *) self + 0x10);
    u8 *q = p;
    if (q) {
        q -= 4;
    }
    if (q != 0) {
        u8 *r = p;
        if (r) {
            r -= 4;
        }
        if (M2C_FIELD(r, u16 *, 0x5ce) & 1) {
            return;
        }
    }
    if (M2C_FIELD(self, u8 *, 0xd) != 1) {
        return;
    }
    M2C_FIELD(self, u8 *, 0xd) = 2;
    M2C_FIELD(self, Entity **, 0x4)->action(0x4a, 0, 1, 0);
    M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u32 *, 0x194) = 0;
    M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u32 *, 0x64)  = 0;
}
