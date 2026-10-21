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

// The class vtable of this object type; it stays in the ROM data.
extern "C" u32 data_020fd6d8[7];

extern "C" void func_02011384(void *, s32);
extern "C" void func_02021b6c();

extern "C" Entity *func_020215a0(Entity *obj, s32 arg1) {
    func_02011384(obj, arg1);
    M2C_FIELD(obj, void **, 0)   = (void *) &data_020fd6d8;
    M2C_FIELD(obj, u8 *, 0x1bc)  = 0;
    M2C_FIELD(obj, u16 *, 0x1be) = 0x96;
    M2C_FIELD(obj, u8 *, 0x216)  = 1;

    if (arg1 == 0x73 || arg1 == 0xa9 || arg1 == 0x8d || arg1 == 0x141 || arg1 == 0x143) {
        obj->action(0x8a, 1, 1, 0);
    }

    if (arg1 == 0xb4) {
        obj->action(0x59, 0, 1, 0);
    }

    if (arg1 == 0x16c || arg1 == 0x16d || arg1 == 0x16e || arg1 == 0x16f || arg1 == 0x14e) {
        M2C_FIELD(obj, u32 *, 0x84) = 0x1b;
        M2C_FIELD(obj, u32 *, 0x18) = (u32) (void *) func_02021b6c;
    }

    if (arg1 == 0x72) {
        M2C_FIELD(obj, u32 *, 8) &= ~0x1000000;
    }

    if (arg1 == 0x136) {
        M2C_FIELD(obj, u32 *, 0x84) = 0x1c;
    }

    return obj;
}
