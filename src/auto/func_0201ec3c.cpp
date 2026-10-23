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

extern "C" void func_020b8f70(M2C_UNK, s32);

extern "C" void func_0201ec3c(Entity *obj) {
    M2C_FIELD(obj, s8 *, 0x1d8) = M2C_FIELD(obj, s8 *, 0x1d8) + 1;
    if (M2C_FIELD(obj, s8 *, 0x1d8) < M2C_FIELD(obj, u8 *, 0x1dc)) {
        return;
    }
    if (M2C_FIELD(obj, u8 *, 0x1bc) != 0) {
        return;
    }
    M2C_FIELD(obj, u8 *, 0x1bc) = 1;
    func_020b8f70(0xba, 0);
    obj->action(0x56, 0, 1, 0);
    u16 v = M2C_FIELD(obj, u16 *, 0x212);
    if (v == 0x60 || v == 0x19) {
        obj->action(0x8b, 0, 1, 0);
        M2C_FIELD(obj, u8 *, 0x1bc) = 4;
    }
    if (M2C_FIELD(obj, u16 *, 0x212) == 0xa7) {
        obj->action(0x8a, 0, 1, 0);
    }
}
