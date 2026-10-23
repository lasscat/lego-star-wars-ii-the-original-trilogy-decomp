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

// Base class constructor called before this object's vptr is installed.
extern "C" void func_02011384(Entity *, int);

// The class vtable of this entity type; it stays in the ROM data.
extern "C" M2C_UNK data_020fd878;

extern "C" void func_02023b1c(Entity *);
extern "C" void func_02023b4c(Entity *);

extern "C" Entity *func_02023870(Entity *obj, int arg) {
    func_02011384(obj, arg);
    M2C_FIELD(obj, u32 *, 0x0)   = (u32) &data_020fd878;
    M2C_FIELD(obj, u32 *, 0x218) = 0;
    M2C_FIELD(obj, u32 *, 0x21c) = 0;
    M2C_FIELD(obj, u8 *, 0x221)  = 0;
    M2C_FIELD(obj, u8 *, 0x222)  = 0;
    if (arg == 0x17f) {
        M2C_FIELD(obj, u8 *, 0x1bc) = 1;
        obj->action(0x8a, 0, 1, 0);
    } else {
        M2C_FIELD(obj, u8 *, 0x1bc) = 0;
        if (M2C_FIELD(obj, u16 *, 0x212) == 0x14) {
            obj->action(0x8a, 0, 1, 0);
        } else {
            obj->action(0x8b, 0, 1, 0);
        }
    }
    M2C_FIELD(obj, u32 *, 0x84) = 0xc;
    if (arg == 0x126) {
        M2C_FIELD(obj, u32 *, 0x18) = (u32) func_02023b4c;
    } else {
        M2C_FIELD(obj, u32 *, 0x10) = (u32) func_02023b1c;
    }
    return obj;
}
