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

// Raw view of the object header: the vptr lives at offset 0.
struct EntityHeader {
    void *vptr;
};

// The class vtable of this entity type; it stays in the ROM data.
extern "C" u32 data_020fd5a0[26];

// Base class constructor called before this object's vptr is installed.
extern "C" void func_02011384(Entity *);

extern "C" Entity *func_020207fc(Entity *obj) {
    func_02011384(obj);
    ((EntityHeader *) obj)->vptr = (void *) &data_020fd5a0;
    M2C_FIELD(obj, u8 *, 0x1bc)  = 0;
    obj->action(0x8a, 1, 1, 0);
    M2C_FIELD(obj, u32 *, 0x8) &= ~0x1000000;
    return obj;
}
