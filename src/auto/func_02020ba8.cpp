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

extern "C" void func_02011384(Entity *obj, int arg);
extern "C" void func_02020e4c(Entity *obj, Entity **arg);
extern "C" M2C_UNK data_020fd608;

extern "C" Entity *func_02020ba8(Entity *obj, int arg) {
    func_02011384(obj, arg);
    M2C_FIELD(obj, u32 *, 0x0)   = (u32) &data_020fd608;
    M2C_FIELD(obj, u32 *, 0x218) = 0;
    M2C_FIELD(obj, u32 *, 0x21c) = 0;
    if (arg == 0x13f) {
        M2C_FIELD(obj, u8 *, 0x1bc) = 7;
    } else {
        M2C_FIELD(obj, u8 *, 0x1bc) = 0;
    }
    obj->action(0x8a, 1, 1, 0);
    M2C_FIELD(obj, u32 *, 0x84) = 0x1b;
    M2C_FIELD(obj, u32 *, 0x18) = (u32) func_02020e4c;
    return obj;
}
