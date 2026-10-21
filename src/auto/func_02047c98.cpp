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

extern "C" M2C_UNK data_02106d90;
extern "C" void func_0209d134(s32, s32);

extern "C" void func_02047c98(void *obj) {
    M2C_FIELD(obj, u8 *, 0xd) = 0;
    M2C_FIELD(M2C_FIELD(obj, Entity **, 0x4), u16 *, 0x1a8) |= 0x80;
    if (M2C_FIELD(obj, u8 *, 0xe) == 0) {
        M2C_FIELD(obj, Entity **, 0x4)->action(0x1d, 0, 1, 0);
    } else {
        M2C_FIELD(obj, Entity **, 0x4)->action(0x1e, 0, 1, 0);
    }
    s32 p = M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s32 *, 0x10);
    if (p == 0) {
        return;
    }
    u32 v = M2C_FIELD(M2C_FIELD(obj, Entity **, 0x4), u8 *, 0x5da);
    if (v >= 4) {
        return;
    }
    func_0209d134(p, (u8) v);
}
