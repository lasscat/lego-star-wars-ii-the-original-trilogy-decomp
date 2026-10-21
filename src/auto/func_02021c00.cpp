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

extern "C" void func_02011384(Entity *self, int arg);
extern "C" u32 data_020fd740[];

extern "C" Entity *func_02021c00(Entity *obj, int arg) {
    func_02011384(obj, arg);
    M2C_FIELD(obj, u32 *, 0x0)   = (u32) data_020fd740;
    M2C_FIELD(obj, u8 *, 0x1bc)  = 0;
    M2C_FIELD(obj, u16 *, 0x1be) = 0x96;
    if (arg == 0x81) {
        obj->action(0, 0, 1, 0);
    } else if (arg == 0x82) {
        obj->action(0, 0, 1, 0);
    } else {
        obj->action(0x58, 0, 1, 0);
    }
    return obj;
}
